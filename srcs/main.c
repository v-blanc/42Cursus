/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:08 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/15 15:06:31 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	exit_usage(void)
{
	printf("Usage: ./philo <number of philosophers> <time to die> ");
	printf("<time to eat> <time to sleep> ");
	printf("[number of times each philosopher must eat]\n");
	return (1);
}

static int	is_valid_digits(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
        str++;
	}
}

static int	is_valid_args(int argc, char **argv)
{
	if (argv[1])
		if (argc == 6)
		{
			// TODO: handle this arg
		}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (exit_usage());
}
