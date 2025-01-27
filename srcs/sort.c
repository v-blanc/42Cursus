/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:17:12 by vblanc            #+#    #+#             */
/*   Updated: 2025/01/27 18:34:23 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// int	is_sorted(t_stack *stack)
// {
// 	int	i;

// 	i = stack->top;
// 	while (i > 0)
// 	{
// 		if (stack->data[i + 1] < stack->data[i])
// 			return (0);
// 		i--;
// 	}
// 	return (1);
// }

// void	ft_sort(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	count_rules;
// 	int	i;
// 	int	j;
// 	int	max_bits;
// 	int	max_value;
// 	int	max_iterations;

// 	max_value = stack_a->data[0];
// 	i = stack_a->top;
// 	while (i >= 0)
// 	{
// 		if (stack_a->data[i] > max_value)
// 			max_value = stack_a->data[i];
// 		i--;
// 	}
// 	max_bits = 0;
// 	while (max_value > 0)
// 	{
// 		max_value = max_value >> 1;
// 		max_bits++;
// 	}
// 	i = 0;
// 	count_rules = 0;
// 	while (i < max_bits)
// 	{
// 		j = stack_a->top;
// 		max_iterations = stack_a->top;
// 		while (max_iterations >= 0)
// 		{
// 			if (((stack_a->data[j] >> i) & 1) == 0)
// 			{
// 				ft_rules(stack_a, stack_b, "pb");
// 				j--;
// 			}
// 			else if (stack_a->top > 0)
// 				ft_rules(stack_a, stack_b, "ra");
// 			max_iterations--;
// 			count_rules++;
// 		}
// 		while (!is_empty(stack_b))
// 		{
// 			ft_rules(stack_a, stack_b, "pa");
// 			count_rules++;
// 		}
// 		if (is_sorted(stack_a) && is_empty(stack_b))
// 			return ;
// 		i++;
// 	}
// 	printf("count_rules: %d\n", count_rules);
// }

// void	ft_sort(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	i;
// 	int	max_bits;
// 	int	max_value;
// 	int	j;
// 	int	stack_a_size;
// 	int	stack_b_size;
// 	int	count_rules;

// 	count_rules = 0;
// 	max_value = stack_a->data[0];
// 	i = stack_a->top;
// 	while (i >= 0)
// 	{
// 		if (stack_a->data[i] > max_value)
// 			max_value = stack_a->data[i];
// 		i--;
// 	}
// 	max_bits = 0;
// 	while (max_value > 0)
// 	{
// 		max_value = max_value >> 1;
// 		max_bits++;
// 	}
// 	for (i = 0; i < max_bits; i++)
// 	{
// 		stack_a_size = stack_a->top + 1;
// 		for (j = 0; j < stack_a_size; j++)
// 		{
// 			if (((stack_a->data[stack_a->top] >> i) & 1) == 0)
// 				ft_rules(stack_a, stack_b, "pb");
// 			else
// 				ft_rules(stack_a, stack_b, "ra");
// 			count_rules++;
// 		}
// 		stack_b_size = stack_b->top + 1;
// 		for (j = 0; j < stack_b_size; j++)
// 		{
// 			if (((stack_b->data[stack_b->top] >> (i + 1)) & 1) == 1)
// 				ft_rules(stack_a, stack_b, "pa");
// 			else
// 				ft_rules(stack_a, stack_b, "rb");
// 			count_rules++;
// 		}
// 	}
// 	while (!is_empty(stack_b))
// 	{
// 		ft_rules(stack_a, stack_b, "pa");
// 		count_rules++;
// 	}
// 	printf("\n\ncount_rules: %d\n\n", count_rules);
// }

// void print_indexes_res(int *indexes, int *values, int number)
// {
// 	int	i;

// 	i = 0;
// 	printf("values    indexes\n");
// 	while (i < number)
// 	{
// 		printf("% 6d % 10d\n", values[i], indexes[i]);
// 		i++;
// 	}
// }

int	*ft_get_indexes(int number, char **input, int *indexes)
{
	int	*values;
	int	i;
	int	j;

	values = malloc(sizeof(int) * number);
	if (!values)
		return (NULL);
	i = 0;
	while (i < number)
	{
		values[i] = ft_atoi(input[i]);
		i++;
	}
	i = 0;
	while (i < number)
	{
		j = 0;
		indexes[i] = 0;
		while (j < number)
		{
			if (values[i] > values[j])
				indexes[i]++;
			j++;
		}
		i++;
	}
	free(values);
	return (indexes);
}

// void	print_stacks(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	i;

// 	if (stack_a->top > stack_b->top)
// 		i = stack_a->top;
// 	else
// 		i = stack_b->top;
// 	while (i >= 0)
// 	{
// 		if (i <= stack_a->top)
// 			printf("%d", stack_a->data[i]);
// 		else
// 			printf(" ");
// 		printf("  ");
// 		if (i <= stack_b->top)
// 			printf("%d", stack_b->data[i]);
// 		printf("\n");
// 		i--;
// 	}
// 	printf("_  _\n");
// 	printf("a  b\n");
// 	printf("-----\n");
// }

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (!is_empty(stack_a))
	{
		while (1)
		{
			// printf("i: %d\n", i);
			// printf("stack_a->data[%d]: %d\n", stack_a->top, stack_a->data[stack_a->top]);
			// print_stacks(stack_a, stack_b);
			// printf("\n------------------------------\n\n");
			if (stack_a->data[stack_a->top] == i)
				break;
			ft_rules(stack_a, stack_b, "ra");
		}
		ft_rules(stack_a, stack_b, "pb");
		i++;
	}
	while (!is_empty(stack_b))
		ft_rules(stack_a, stack_b, "pa");
}
