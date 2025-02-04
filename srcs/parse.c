/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:16:22 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/04 13:27:58 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_check_doubles(char **input, int *values, int *number)
{
	int	i;
	int	j;
	int	len;

	len = ft_input_len(input);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (values[i] == values[j])
			{
				if (*number == 2)
					ft_free_split(input);
				free(values);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	ft_check_input(char **input, int *values, int *number)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if ((!ft_isdigit(input[i][j]) && input[i][j] != '-')
				|| ft_intlen(values[i]) != (int)ft_strlen(input[i]))
			{
				if (*number == 2)
					ft_free_split(input);
				free(values);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	ft_check_doubles(input, values, number);
}

static void	sub_get_indexes(int **indexes, char **input, int *values,
		int number)
{
	int	i;
	int	j;

	*indexes = malloc(sizeof(int) * ft_input_len(input));
	if (!*indexes)
	{
		if (number == 2)
			ft_free_split(input);
		free(values);
		exit(1);
	}
	i = 0;
	while (i < ft_input_len(input))
	{
		j = 0;
		(*indexes)[i] = 0;
		while (j < ft_input_len(input))
		{
			if (values[i] > values[j])
				(*indexes)[i]++;
			j++;
		}
		i++;
	}
}

void	ft_get_indexes(int *number, char **input, int **indexes)
{
	int	*values;
	int	i;

	if (*number == 2)
	{
		input = ft_split(input[0], ' ');
		if (!input)
			exit(1);
	}
	values = ft_calloc(ft_input_len(input), sizeof(int));
	if (!values)
	{
		if (*number == 2)
			ft_free_split(input);
		exit(1);
	}
	i = -1;
	while (input[++i])
		values[i] = ft_atoi(input[i]);
	ft_check_input(input, values, number);
	sub_get_indexes(indexes, input, values, *number);
	if (*number == 2)
		ft_free_split(input);
	free(values);
	*number = i + 1;
}
