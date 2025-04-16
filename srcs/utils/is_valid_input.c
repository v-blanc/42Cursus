/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:18:35 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/16 13:22:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_usage(void)
{
	printf("Usage: ./philo <number of philosophers> <time to die> ");
	printf("<time to eat> <time to sleep> ");
	printf("[number of times each philosopher must eat]\n");
}

static int	is_digits(const char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

static int	is_valid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_digits(argv[i]))
			return (0);
		if (ft_strlen(argv[i]) > 10)
			return (0);
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_input(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		print_usage();
		return (0);
	}
	if (!is_valid_args(argc, argv))
	{
		print_usage();
		return (0);
	}
	return (1);
}
