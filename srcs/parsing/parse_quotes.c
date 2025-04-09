#include "../../include/minishell.h"

int	test_quotes_validity(char *input_str)
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

static int	sub_parse_quotes(char *input, char **new_input, int *ind,
		t_garbage_collector **head)
{
	char	*tmp;
	char	*sub_input;

	if (ind[2] == 0)
	{
		ind[2] = 1;
		ind[3] = ind[0];
	}
	else
	{
		// TODO: create gc_substr function or use another way
		sub_input = ft_substr(input, ind[3], ind[0] - ind[3] + 1);
		if (sub_input == NULL)
			return (1);
		if (get_env_value(&tmp, sub_input, head))
			return (1);
		ft_strlcat((*new_input), tmp, ft_strlen((*new_input)) + ft_strlen(tmp)
			+ 1);
		ind[2] = 0;
		ind[1] = ft_strlen((*new_input));
	}
	return (0);
}

int	parse_quotes(char *input, char **new_input, t_garbage_collector **head)
{
	int	ind[4];

	// TODO: fix the size `10000`
	(*new_input) = gc_malloc(10000 * sizeof(char), head);
	if (!(*new_input))
		return (1);
	ind[0] = 0;
	ind[1] = 0;
	ind[2] = 0;
	ind[3] = 0;
	while (input[ind[0]])
	{
		if (input[ind[0]] == '"')
		{
			if (sub_parse_quotes(input, new_input, ind, head))
				return (1);
		}
		// else if (input[ind[0]] == '$')
		// {
		// }
		else if (ind[2] == 0)
			(*new_input)[ind[1]++] = input[ind[0]];
		ind[0]++;
	}
	return (0);
}

int	testing_parsing(char *input_str, t_garbage_collector **head)
{
	char	*new_input;

	// (void)head;
	printf("\nquotes validity: \n>>>%s<<<\n",
		test_quotes_validity(input_str) == 0 ? "VALID" : "INVALID");
	new_input = NULL;
	parse_quotes(input_str, &new_input, head);
	printf("\ninput with env: \n>>>%s<<<\n\n", new_input);
	return (0);
}
