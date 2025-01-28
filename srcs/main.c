/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:02:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/01/28 20:05:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->top > stack_b->top)
		i = stack_a->top;
	else
		i = stack_b->top;
	while (i >= 0)
	{
		if (i <= stack_a->top)
			printf("%d", stack_a->data[i]);
		else
			printf(" ");
		printf("  ");
		if (i <= stack_b->top)
			printf("%d", stack_b->data[i]);
		printf("\n");
		i--;
	}
	printf("_  _\n");
	printf("a  b\n");
	printf("-----\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*indexes;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	indexes = ft_get_indexes(&argc, &argv[1]);
	stack_a = fill_stack(argc - 1, indexes);
	if (!stack_a || check_stack_validity(stack_a) == 0)
	{
		free(indexes);
		write(2, "Error\n", 6);
		return (0);
	}
	stack_b = init_stack(argc - 1);
	if (!stack_b)
	{
		free(indexes);
		free_stack(stack_a);
		write(2, "Error\n", 6);
		return (0);
	}
	// print_stacks(stack_a, stack_b);
	ft_sort(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
