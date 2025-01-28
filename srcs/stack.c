/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:01:00 by vblanc            #+#    #+#             */
/*   Updated: 2025/01/28 22:05:09 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = ft_calloc(capacity, sizeof(int));
	if (!stack->data)
		return (NULL);
	stack->capacity = capacity;
	stack->top = -1;
	return (stack);
}

t_stack	*fill_stack(int capacity, int *data)
{
	t_stack	*stack;
	int		i;

	stack = init_stack(capacity);
	if (!stack)
		return (NULL);
	i = capacity - 1;
	while (i >= 0)
	{
		stack->data[capacity - i - 1] = data[i];
		stack->top++;
		i--;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->data);
	free(stack);
}

int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}
