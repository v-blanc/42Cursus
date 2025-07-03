/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_manual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:35:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/07 16:11:57 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_min(t_stack *stack)
{
	int	min;
	int	i;

	min = stack->data[0];
	i = 0;
	while (i <= stack->top)
	{
		if (stack->data[i] < min)
			min = stack->data[i];
		i++;
	}
	return (min);
}

static void	ft_sort_2(t_stack *stack, char stack_name)
{
	int	min;

	min = ft_get_min(stack);
	if (stack_name == 'a')
	{
		if (stack->data[stack->top] == min + 1)
			ft_rules(stack, NULL, "sa");
	}
	else
	{
		if (stack->data[stack->top] == min)
			ft_rules(NULL, stack, "sb");
	}
}

static void	ft_sort_3(t_stack *stack)
{
	int	min;

	min = ft_get_min(stack);
	if (stack->data[2] == min && stack->data[1] == min + 2)
	{
		ft_rules(stack, NULL, "sa");
		ft_rules(stack, NULL, "ra");
	}
	if (stack->data[2] == min + 1)
	{
		if (stack->data[1] == min)
			ft_rules(stack, NULL, "sa");
		else
			ft_rules(stack, NULL, "rra");
	}
	if (stack->data[2] == min + 2)
	{
		if (stack->data[1] == min)
			ft_rules(stack, NULL, "ra");
		else
		{
			ft_rules(stack, NULL, "sa");
			ft_rules(stack, NULL, "rra");
		}
	}
}

static void	ft_sort_4(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top > 2)
	{
		if (stack_a->data[stack_a->top] == 0)
			ft_rules(stack_a, stack_b, "pb");
		else
			ft_rules(stack_a, stack_b, "ra");
	}
	ft_sort_3(stack_a);
	ft_rules(stack_a, stack_b, "pa");
}

void	ft_manual_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->capacity == 2)
		ft_sort_2(stack_a, 'a');
	else if (stack_a->capacity == 3)
		ft_sort_3(stack_a);
	else if (stack_a->capacity == 4)
		ft_sort_4(stack_a, stack_b);
	else if (stack_a->capacity == 5)
	{
		while (stack_a->top >= 3)
		{
			if (stack_a->data[stack_a->top] <= 1)
				ft_rules(stack_a, stack_b, "pb");
			else
				ft_rules(stack_a, stack_b, "ra");
		}
		ft_sort_3(stack_a);
		ft_sort_2(stack_b, 'b');
		while (!is_empty(stack_b))
			ft_rules(stack_a, stack_b, "pa");
	}
}
