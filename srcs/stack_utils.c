/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:09:18 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/22 01:26:05 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = tmp;
}

void	ft_push(t_stack *first_stack, t_stack *second_stack)
{
	if (second_stack->top == -1)
		return ;
	first_stack->data[++first_stack->top] = second_stack->data[second_stack->top--];
}

void	ft_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->data[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;
}

void	ft_reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;
	int	top;

	top = stack->top;
	if (top < 1)
		return ;
	tmp = stack->data[0];
	i = 0;
	while (i < top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = tmp;
}

int	check_stack_validity(t_stack *stack)
{
	int	i;
	int	top;
	int	value;

	top = stack->top;
	i = 0;
	while (i <= top)
	{
		value = stack->data[i];
		i++;
		while (i <= top)
		{
			if (stack->data[i] == value)
				return (0);
			i++;
		}
	}
	return (1);
}
