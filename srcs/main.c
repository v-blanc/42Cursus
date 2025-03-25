#include "../include/minishell.h"

char	*set_readline_prompt(void)
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
	rl_prompt = ft_strjoin("\033[1;32mminishell\033[0m:\033[1;34m", pwd);
	if (!rl_prompt)
		return (NULL);
	final_rl_prompt = ft_strjoin(rl_prompt, "\033[0m$\033[0m ");
	if (!final_rl_prompt)
		return (free(rl_prompt), NULL);
	free(rl_prompt);
	return (final_rl_prompt);
}

void	set_input(void)
{
	char	*input;
	char	*rl_prompt;

	rl_clear_history();
	while (1)
	{
		rl_prompt = set_readline_prompt();
		input = readline(rl_prompt);
		if (!input) // EOF ie CTRL-D
			return (free(rl_prompt), free(input), printf("exit\n"), exit(0));
		if (rl_prompt != NULL)
			free(rl_prompt);
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
		// export(NULL); // TESTING EXPORT
		// pwd(); // TESTING PWD
		free(input);
	}
	rl_clear_history();
}

extern char	**environ;

int	main(void)
{
	init_sig();
	set_input();
	return (0);
}
