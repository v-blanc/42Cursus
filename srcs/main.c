#include "../include/minishell.h"

char	*set_readline_prompt(t_garbage_collector **head)
{
	char	*rl_prompt;
	char	*final_rl_prompt;
	char	pwd[PATH_MAX];
	char	*pwd_home;

	ft_strlcpy(pwd, getenv("PWD"), PATH_MAX);
	pwd_home = getenv("HOME");
	if (!ft_strncmp(pwd, pwd_home, ft_strlen(pwd_home)))
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
		// cd(input, head); // TESTING CD
		// echo(input, true); // TESTING ECHO
		// gc_setenv("TEST", "test", head);
		// env(); // TESTING ENV
		export(input, NULL, head); // TESTING EXPORT
		export(NULL, NULL, head);  // TESTING EXPORT
		// pwd(); // TESTING PWD
		free(input);
	}
	rl_clear_history();
}

extern char	**environ;

int	main(void)
{
	t_garbage_collector	*head;

	head = NULL;
	init_sig();
	set_input(&head);
	return (0);
}
