#include "../../include/minishell.h"

int	get_quotes(char *input_str)
{
	t_stack	stack;
	int		i;

	init_stack(&stack);
	i = 0;
	while (input_str[i])
	{
		if (input_str[i] == '"' || input_str[i] == '\'')
		{
			if (is_stack_empty(&stack) || top_stack(&stack) != input_str[i])
			{
				if (push_stack(&stack, input_str[i]))
					return (1);
			}
			else
			{
				if (pop_stack(&stack) != input_str[i])
					return (1);
			}
		}
		i++;
	}
	if (!is_stack_empty(&stack))
		return (1);
	return (0);
}

int	testing_parsing(char *input_str, t_garbage_collector **head)
{
	char **input;

	(void)head;
	input = NULL;
	printf(">>>%s<<<\n", get_quotes(input_str) == 0 ? "VALID" : "INVALID");
	// if (get_quotes(input_str))
	// 	return (1);
	// printf("\n\n>>>>");
	// for (int i = 0; input[i]; i++)
	// 	printf("%s ", input[i]);
	// printf("\n");
	return (0);
}