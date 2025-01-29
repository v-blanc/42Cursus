/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:17:12 by vblanc            #+#    #+#             */
/*   Updated: 2025/01/29 13:02:53 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_sort_3(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->data[stack_a->top] == 0)
	{
		if (stack_a->data[stack_a->top] == 2)
		{
			ft_rules(stack_a, stack_b, "ra");
			ft_rules(stack_a, stack_b, "sa");
			ft_rules(stack_a, stack_b, "rra");
		}
	}
	else if (stack_a->data[stack_a->top] == 1)
	{
		if (stack_a->data[1] == 0)
			ft_rules(stack_a, stack_b, "sa");
		else
			ft_rules(stack_a, stack_b, "rra");
	}
	else
	{
		if (stack_a->data[1] == 0)
			ft_rules(stack_a, stack_b, "ra");
		else
		{
			ft_rules(stack_a, stack_b, "sa");
			ft_rules(stack_a, stack_b, "rra");
		}
	}
}

void	ft_manual_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->capacity == 2)
	{
		if (stack_a->data[1] == 1)
			ft_rules(stack_a, stack_b, "sa");
	}
	else if (stack_a->capacity == 3)
		ft_sort_3(stack_a, stack_b);
}

static int	ft_get_max(int number)
{
	int	max;

	max = 0;
	while (number > 0)
	{
		max++;
		number /= 2;
	}
	return (max);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bit;
	int	max;
	int	i;

	max = ft_get_max(stack_a->top);
	bit = 0;
	while (bit < max)
	{
		i = 0;
		while (i < stack_a->capacity)
		{
			if (stack_a->data[stack_a->top] >> bit & 1)
				ft_rules(stack_a, stack_b, "ra");
			else
				ft_rules(stack_a, stack_b, "pb");
			i++;
		}
		while (!is_empty(stack_b))
			ft_rules(stack_a, stack_b, "pa");
		bit++;
	}
}
