#include "../include/minishell.h"

char	*set_readline_prompt(t_gc **head)
{
	char	*rl_prompt;
	char	*final_rl_prompt;
	char	pwd[PATH_MAX];
	char	*pwd_home;

	ft_strlcpy(pwd, getenv("PWD"), PATH_MAX);
	pwd_home = getenv("HOME");
	if (pwd_home != NULL && !ft_strncmp(pwd, pwd_home, ft_strlen(pwd_home)))
	{
		ft_strlcpy(pwd, pwd + ft_strlen(pwd_home) - 1, PATH_MAX);
		pwd[0] = '~';
	}
	rl_prompt = gc_strjoin("minishell:", pwd, head);
	if (!rl_prompt)
		return (NULL);
	final_rl_prompt = gc_strjoin(rl_prompt, "$ ", head);
	if (!final_rl_prompt)
		return (NULL);
	gc_free(rl_prompt, head);
	return (final_rl_prompt);
}

void	set_input(t_context **context, t_gc **head)
{
	char	*input;
	char	*rl_prompt;

	while (1)
	{
		rl_prompt = set_readline_prompt(head);
		input = readline(rl_prompt);
		if (rl_prompt != NULL)
			gc_free(rl_prompt, head);
		if (!input) // EOF ie CTRL-D
			return (free(input), printf("exit\n"), exit(0));
		testing_parser(input, context, head);
		add_history(input);
		free(input);
		gc_free_all(head);
	}
	free(input);
	gc_free_all_perm(*head);
	rl_clear_history();
	exit(0);
}

extern char	**environ;

int	init_environ(t_gc **head)
{
	char	*env_pwd;

	if (environ == NULL || environ[0] == NULL)
	{
		environ = (char **)gc_malloc_array_perm(3, head);
		if (getcwd(env_pwd, PATH_MAX) == NULL)
		{
			print(2, "getcwd: %s\n", strerror(errno));
			return (1);
		}
		environ[0] = gc_strjoin_perm("PWD=", env_pwd, head);
		environ[1] = gc_strjoin_perm("SHLVL=1", "", head);
		// TODO: change to use `which env` ou autre ?
		environ[2] = gc_strjoin_perm("_=/usr/bin/env", "", head);
		environ[3] = NULL;
		if (!environ[0] || !environ[1] || !environ[2])
			return (1);
	}
	return (0);
}

int	init_context(t_context **context, int argc, char **argv, t_gc **head)
{
	(*context) = gc_malloc_perm(sizeof(t_context), head);
	if (!(*context))
		return (1);
	(*context)->argc = argc;
	(*context)->argv = argv;
	(*context)->last_exit_status = 22222;
	(*context)->head = head;
	return (0);
}

int	main(int argc, char **argv)
{
	t_gc		*head;
	t_context	*context;

	if (argc > 2) // TODO: rework to allow multiple arguments
		return (1);
	head = NULL;
	context = NULL;
	if (init_context(&context, argc, argv, &head))
		return (1);
	init_sig();
	if (init_environ(&head))
		return (1);
	set_input(&context, &head);
	return (0);
}
