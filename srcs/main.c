/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:02:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/01/28 22:19:55 by vblanc           ###   ########.fr       */
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



int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*indexes;

	// TODO: handle stdin (p. 9)
	// if (argc < 2)
	// {
	// 	write(2, "Error\n", 6);
	// 	return (1);
	// }
	ft_get_indexes(&argc, &argv[1], &indexes);
	if (!indexes)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	ft_init_stacks(&stack_a, &stack_b, argc, indexes);
	ft_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
