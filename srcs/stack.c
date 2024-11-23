/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:01:00 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/22 01:25:58 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		return (NULL);
	stack->data = ft_calloc(capacity, sizeof(int));
	if (!stack->data)
		return (NULL);
	stack->capacity = capacity;
	stack->top = -1;
	return (stack);
}

t_stack	*fill_stack(int capacity, char **data)
{
	int		i;
	int		data_converted;
	t_stack	*stack;

	stack = init_stack(capacity);
	if (!stack)
		return (NULL);
	i = capacity - 1;
	while (i >= 0)
	{
		data_converted = ft_atoi(data[i]);
		if ((ft_intlen(data_converted) != (int)ft_strlen(data[i]))
			|| (data_converted == 0 && ft_strncmp(data[i], "0",
					ft_strlen(data[i]))))
		{
			free_stack(stack);
			return (NULL);
		}
		stack->data[capacity - i - 1] = data_converted;
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
