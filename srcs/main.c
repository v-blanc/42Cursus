#include "../include/minishell.h"

char	*set_readline_prompt(t_garbage_collector **head)
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
	rl_prompt = gc_strjoin("\033[1;32mminishell\033[0m:\033[1;34m", pwd, head);
	if (!rl_prompt)
		return (NULL);
	final_rl_prompt = gc_strjoin(rl_prompt, "\033[0m$\033[0m ", head);
	if (!final_rl_prompt)
		return (NULL);
	gc_free(rl_prompt, head);
	return (final_rl_prompt);
}

void	set_input(t_garbage_collector **head)
{
	char	*input;
	char	*rl_prompt;

	// char	**to_unset;
	while (1)
	{
		rl_prompt = set_readline_prompt(head);
		input = readline(rl_prompt);
		if (rl_prompt != NULL)
			gc_free(rl_prompt, head);
		if (!input) // EOF ie CTRL-D
			return (free(input), printf("exit\n"), exit(0));
		// TODO: remove when exit is implemented
		if (ft_strcmp(input, "exit") == 0)
		{
			free(input);
			gc_free_all(*head);
			rl_clear_history();
			exit(0);
		}
		add_history(input);
		if (cd(input, head))
			break ; // TESTING CD
		// echo(input, true); // TESTING ECHO
		// gc_setenv("TEST", "test", head);
		// export("TEST", input, head);      // TESTING EXPORT
		// env();                            // TESTING ENV
		// to_unset = ft_split("TEST", ' '); // tmp can leak
		// unset(to_unset, head);            // TESTING UNSET
		// for (int i = 0; to_unset[i]; i++) // tmp can leak
		// 	free(to_unset[i]);
		// free(to_unset); // tmp can leak
		// env();          // TESTING ENV
		// export(NULL, NULL, head);    // TESTING EXPORT
		// pwd(); // TESTING PWD
		// printf(">> %s\n", getenv(input));
		free(input);
	}
	free(input);
	gc_free_all(*head);
	rl_clear_history();
	exit(0);
}

extern char	**environ;

int	init_environ(t_garbage_collector **head)
{
	if (environ == NULL || environ[0] == NULL)
	{
		environ = (char **)gc_malloc_array(3, head);
		environ[0] = gc_strjoin("PWD=", getcwd(NULL, 0), head);
		environ[1] = gc_strjoin("SHLVL=1", "", head);
		// TODO: change to use `which env` ?
		environ[2] = gc_strjoin("_=/usr/bin/env", "", head);
		environ[3] = NULL;
		if (!environ[0] || !environ[1] || !environ[2])
			return (1);
	}
	return (0);
}

int	main(void)
{
	t_garbage_collector	*head;

	head = NULL;
	init_sig();
	if (init_environ(&head))
		return (1);
	set_input(&head);
	return (0);
}
