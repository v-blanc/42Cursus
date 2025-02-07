/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:09:18 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/07 16:11:48 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = tmp;
}

void	ft_push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top == -1)
		return ;
	stack_a->data[++stack_a->top] = stack_b->data[stack_b->top--];
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
