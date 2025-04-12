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

// int	testing(char *input, t_gc **head)
// {
// 	char	**split_input;
// 	char	*new_input;

// 	if (!input)
// 		return (1);
// 	if (!input[0])
// 	{
// 		// TODO: set exit status to 130
// 		return (1);
// 	}
// 	if (test_quotes_validity(input))
// 		return (1);
// 	new_input = NULL;
// 	parse_quotes(input, &new_input, head);
// 	split_input = ft_split(new_input, ' ');
// 	if (!split_input)
// 		return (1);
// 	if (!ft_strcmp(split_input[0], "exit"))
// 		return (1);
// 	else if (!ft_strcmp(split_input[0], "cd"))
// 		cd(split_input[1], head);
// 	else if (!ft_strcmp(split_input[0], "echo"))
// 	{
// 		printf("Caution: echo have to be reworked\n");
// 		echo(split_input[1], false);
// 	}
// 	else if (!ft_strcmp(split_input[0], "env"))
// 		env();
// 	else if (ft_strcmp(input, "exit") == 0)
// 	{
// 		free(input);
// 		gc_free_all(*head);
// 		rl_clear_history();
// 		exit(0);
// 	}
// 	else if (!ft_strcmp(split_input[0], "export"))
// 	{
// 		if (!split_input[2])
// 			export(split_input[1], "", head);
// 		else
// 			export(split_input[1], split_input[2], head);
// 	}
// 	else if (!ft_strcmp(split_input[0], "pwd"))
// 		pwd();
// 	else if (!ft_strcmp(split_input[0], "unset"))
// 		unset(split_input + 1, head);
// 	else
// 		printf("minishell: Command not found\n");
// 	for (int i = 0; split_input[i]; i++)
// 		free(split_input[i]);
// 	free(split_input);
// 	return (0);
// }

void	set_input(t_context *context, t_gc **head)
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
		if (ft_strcmp(input, "exit") == 0)
		{
			free(input);
			gc_free_all(*head);
			rl_clear_history();
			exit(0);
		}
		// testing(input, head);
		// testing_input(input, head);
		testing_parser(input, context, head);
		add_history(input);
		free(input);
	}
	free(input);
	gc_free_all(*head);
	rl_clear_history();
	exit(0);
}

extern char	**environ;

int	init_environ(t_gc **head)
{
	if (environ == NULL || environ[0] == NULL)
	{
		environ = (char **)gc_malloc_array(3, head);
		environ[0] = gc_strjoin("PWD=", getcwd(NULL, 0), head);
		environ[1] = gc_strjoin("SHLVL=1", "", head);
		// TODO: change to use `which env` ou autre ?
		environ[2] = gc_strjoin("_=/usr/bin/env", "", head);
		environ[3] = NULL;
		if (!environ[0] || !environ[1] || !environ[2])
			return (1);
	}
	return (0);
}

int	init_context(t_context **context, int argc, char **argv, t_gc **head)
{
	(*context) = gc_malloc(sizeof(t_context), head);
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
	init_context(&context, argc, argv, &head);
	init_sig();
	if (init_environ(&head))
		return (1);
	set_input(context, &head);
	return (0);
}
