#include "../include/minishell.h"

char	*set_readline_prompt(void)
{
	char	*readline_prompt;
	char	*final_readline_prompt;
	char	pwd[PATH_MAX];
	char	*pwd_home;

	ft_strlcpy(pwd, getenv("PWD"), PATH_MAX);
	pwd_home = getenv("HOME");
	if (!ft_strncmp(pwd, pwd_home, ft_strlen(pwd_home)))
	{
		ft_strlcpy(pwd, pwd + ft_strlen(pwd_home) - 1, PATH_MAX);
		pwd[0] = '~';
	}
	readline_prompt = ft_strjoin("\033[1;32mminishell\033[0m:\033[1;34m", pwd);
	if (!readline_prompt)
		return (NULL);
	final_readline_prompt = ft_strjoin(readline_prompt, "\033[0m$\033[0m ");
	if (!final_readline_prompt)
		return (free(readline_prompt), NULL);
	free(readline_prompt);
	return (final_readline_prompt);
}

void	set_input(void)
{
	char	*input;
	char	*readline_prompt;

	rl_clear_history();
	while (1)
	{
		readline_prompt = set_readline_prompt();
		input = readline(readline_prompt);
		if (!input) // EOF ie CTRL-D
			return (free(readline_prompt), free(input), exit(0));
		if (readline_prompt != NULL)
			free(readline_prompt);
		// TODO: remove when exit is implemented
		if (ft_strcmp(input, "exit") == 0)
		{
			free(input);
			rl_clear_history();
			exit(0);
		}
		add_history(input);
		// cd(input); // TESTING CD
		// echo(input, true); // TESTING ECHO
		// env(); // TESTING ENV
		export(NULL); // TESTING EXPORT
		// pwd(); // TESTING PWD
		free(input);
	}
	rl_clear_history();
}

extern char	**environ;

int	main(void)
{
	set_input();
	return (0);
}
