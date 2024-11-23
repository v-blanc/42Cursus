/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:17:12 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/23 20:53:40 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i > 0)
	{
		if (stack->data[i + 1] < stack->data[i])
			return (0);
		i--;
	}
	return (1);
}

void	ft_sort_radix(t_stack *stack_a, t_stack *stack_b)
{
	int	count_rules;
	int	i;
	int	j;
	int	max_bits;
	int	max_value;
	int	max_iterations;

	max_value = stack_a->data[0];
	i = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->data[i] > max_value)
			max_value = stack_a->data[i];
		i--;
	}
	max_bits = 0;
	while (max_value > 0)
	{
		max_value = max_value >> 1;
		max_bits++;
	}
	i = 0;
	count_rules = 0;
	while (i < max_bits)
	{
		j = stack_a->top;
		max_iterations = stack_a->top;
		while (max_iterations >= 0)
		{
			if (((stack_a->data[j] >> i) & 1) == 0)
			{
				ft_rules(stack_a, stack_b, "pb");
				j--;
			}
			else if (stack_a->top > 0)
				ft_rules(stack_a, stack_b, "ra");
			max_iterations--;
			count_rules++;
		}
		while (!is_empty(stack_b))
		{
			ft_rules(stack_a, stack_b, "pa");
			count_rules++;
		}
		if (is_sorted(stack_a) && is_empty(stack_b))
			return ;
		i++;
	}
	printf("count_rules: %d\n", count_rules);
}
*/

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_bits;
	int	max_value;
	int	j;
	int	stack_a_size;
	int	stack_b_size;

	max_value = stack_a->data[0];
	i = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->data[i] > max_value)
			max_value = stack_a->data[i];
		i--;
	}
	max_bits = 0;
	while (max_value > 0)
	{
		max_value = max_value >> 1;
		max_bits++;
	}
	for (i = 0; i < max_bits; i++)
	{
		stack_a_size = stack_a->top + 1;
		for (j = 0; j < stack_a_size; j++)
		{
			if (((stack_a->data[stack_a->top] >> i) & 1) == 0)
				ft_rules(stack_a, stack_b, "pb");
			else
				ft_rules(stack_a, stack_b, "ra");
		}
		stack_b_size = stack_b->top + 1;
		for (j = 0; j < stack_b_size; j++)
		{
			if (((stack_b->data[stack_b->top] >> (i + 1)) & 1) == 1)
				ft_rules(stack_a, stack_b, "pa");
			else
				ft_rules(stack_a, stack_b, "rb");
		}
	}
	while (!is_empty(stack_b))
		ft_rules(stack_a, stack_b, "pa");
}
