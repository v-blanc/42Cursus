/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:17:12 by vblanc            #+#    #+#             */
/*   Updated: 2025/01/28 20:04:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_input_len(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

int	*ft_get_indexes(int *number, char **input)
{
	int	*values;
	int	*indexes;
	int	i;
	int	j;

	if (*number == 2)
	{
		input = ft_split(input[0], ' ');
		if (!input)
			return (NULL);
	}
	values = ft_calloc(ft_input_len(input), sizeof(int));
	if (!values)
		return (NULL);
	i = -1;
	while (input[++i])
		values[i] = ft_atoi(input[i]);
	indexes = malloc(sizeof(int) * i);
	if (!indexes)
	{
		if (*number == 2)
			free(input);
		free(values);
		return (0);
	}
	i = 0;
	while (input[i])
	{
		j = 0;
		indexes[i] = 0;
		while (input[j])
		{
			if (values[i] > values[j])
				indexes[i]++;
			j++;
		}
		i++;
	}
	if (*number == 2)
		free(input);
	free(values);
	*number = i + 1;
	return (indexes);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (!is_empty(stack_a))
	{
		while (1)
		{
			if (stack_a->data[stack_a->top] == i)
				break ;
			ft_rules(stack_a, stack_b, "ra");
		}
		ft_rules(stack_a, stack_b, "pb");
		i++;
	}
	while (!is_empty(stack_b))
		ft_rules(stack_a, stack_b, "pa");
}
