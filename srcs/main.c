/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:02:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/01/28 17:35:39 by vblanc           ###   ########.fr       */
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

// void	print_stack_binary(t_stack *stack)
// {
// 	int	i;
// 	int	value;

// 	i = 0;
// 	while (i <= stack->top)
// 	{
// 		value = stack->data[i];
// 		printf("%d: ", value);
// 		while (value > 0)
// 		{
// 			if ((value & 1) == 1)
// 				printf("1");
// 			else
// 				printf("0");
// 			value = value >> 1;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

// void print_indexes_res(int *indexes, int number)
// {
// 	int	i;

// 	i = 0;
// 	printf("indexes\n");
// 	while (i < number)
// 	{
// 		printf("% 2d\n", indexes[i]);
// 		i++;
// 	}
// 	printf("\n\n");
// }

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	int		*indexes;

// 	if (argc < 2)
// 		return (0);
// 	stack_a = fill_stack(argc - 1, &argv[1]);
// 	if (!stack_a || check_stack_validity(stack_a) == 0)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	stack_b = init_stack(0);
// 	if (!stack_b)
// 	{
// 		free_stack(stack_a);
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	indexes = malloc(sizeof(int) * (argc - 1));
// 	if (!indexes)
// 	{
// 		free_stack(stack_a);
// 		free_stack(stack_b);
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	ft_get_indexes(argc - 1, &argv[1], indexes);
// 	// print_stacks(stack_a, stack_b);
// 	// print_stack_binary(stack_a);
// 	// ft_sort(stack_a, stack_b);
// 	print_stacks(stack_a, stack_b);
// 	free_stack(stack_a);
// 	free_stack(stack_b);
// 	return (0);
// }

// int check_input_type(char *input)
// {
// 	int	i;

// 	i = 0;
// 	while (input[i])
// 	{
// 		if ((input[i] < '0' || input[i] > '9') && input[i] != ' ')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int *indexes;

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
	stack_b = init_stack(0);
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