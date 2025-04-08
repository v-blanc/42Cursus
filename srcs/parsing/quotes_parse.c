#include "../../include/minishell.h"

int	get_quotes(char *input_str, char *last_quote)
{
	t_stack	stack;
	int		i;

	init_stack(&stack);
	i = 0;
	while (input_str[i])
	{
		if (input_str[i] == '"' || input_str[i] == '\'')
		{
			if (!is_stack_empty(&stack) && top_stack(&stack) == input_str[i])
			{
				*last_quote = input_str[i];
				if (pop_stack(&stack) != input_str[i])
					return (1);
			}
			else if (push_stack(&stack, input_str[i]))
				return (1);
		}
		i++;
	}
	return (!is_stack_empty(&stack));
}

// int	testing_parsing(char *input_str, t_garbage_collector **head)
// {
// 	char **input;

// 	(void)head;
// 	input = NULL;
// 	char last_quote = '\0';
// 	printf(">>>%s<<<\n", get_quotes(input_str,
// 			&last_quote) == 0 ? "VALID" : "INVALID");
// 	printf("last quote: %c\n", last_quote);
// 	// if (get_quotes(input_str))
// 	// 	return (1);
// 	// printf("\n\n>>>>");
// 	// for (int i = 0; input[i]; i++)
// 	// 	printf("%s ", input[i]);
// 	// printf("\n");
// 	return (0);
// }