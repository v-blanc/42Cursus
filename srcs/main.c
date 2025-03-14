#include "../include/minishell.h"

void	set_input(void)
{
	char	*input;

	rl_clear_history();
	while (1)
	{
		printf("minishell:%s$ ", getenv("PWD"));
		input = readline("");
		if (!input)
		{
			printf("error\n");
			return ;
		}
        // TODO: remove when exit is implemented
		if (ft_strcmp(input, "exit") == 0)
			exit(0);
		if (ft_strcmp(input, "") == 0)
			printf("\n");
		// printf("%s\n", input);
		add_history(input);
		free(input);
	}
}

int	main(void)
{
	set_input();
	return (0);
}
