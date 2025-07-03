/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:02:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/07 16:11:44 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_init_stacks(t_stack **stack_a, t_stack **stack_b, int argc,
		int *ind)
{
	*stack_a = fill_stack(argc - 1, ind);
	if (!*stack_a)
	{
		free(ind);
		write(2, "Error\n", 6);
		exit(1);
	}
	*stack_b = init_stack(argc - 1);
	if (!*stack_b)
	{
		free(ind);
		free_stack(*stack_a);
		write(2, "Error\n", 6);
		exit(1);
	}
	free(ind);
}

static int	ft_is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->capacity - 1)
	{
		if (stack->data[i] < stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_arg(int argc, char **argv)
{
	char	*number;
	char	**input;
	int		flag;

	if (argc > 2)
		return (0);
	input = ft_split(argv[1], ' ');
	if (!input)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ft_input_len(input) == 1)
	{
		number = ft_itoa(ft_atoi(argv[1]));
		flag = ft_strncmp(input[0], number, ft_strlen(input[0]));
		free(number);
		if (!flag)
		{
			ft_free_split(input);
			return (1);
		}
	}
	ft_free_split(input);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*indexes;

	if (argc < 2 || ft_check_arg(argc, argv))
		return (0);
	ft_get_indexes(&argc, &argv[1], &indexes);
	if (!indexes)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	ft_init_stacks(&stack_a, &stack_b, argc, indexes);
	if (!ft_is_sorted(stack_a))
	{
		if (stack_a->capacity <= 5)
			ft_manual_sort(stack_a, stack_b);
		else
			ft_sort(stack_a, stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
