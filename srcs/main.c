#include "../include/minishell.h"

char	*set_readline_prompt(void)
{
	char	*readline_prompt;
	char	*pwd;

	readline_prompt = "minishell:";
	pwd = getcwd(NULL, 0);
	if (pwd)
		readline_prompt = ft_strjoin(readline_prompt, pwd);
	readline_prompt = ft_strjoin(readline_prompt, "$ ");
	return (readline_prompt);
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
		free(readline_prompt);
		if (!input)
		{
			printf("error\n");
			return ;
		}
		// TODO: remove when exit is implemented
		if (ft_strcmp(input, "exit") == 0)
			exit(0);
		add_history(input);
		cd(input); // TESTING CD
		free(input);
	}
}

extern char	**environ;

int	main(void)
{
	set_input();
	return (0);
}
