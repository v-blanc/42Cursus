/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:02:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/01/31 15:37:22 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	while (i < stack->capacity)
	{
		if (stack->data[i] < stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*indexes;

	if (argc < 2)
		return (1);
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
