/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:08 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/16 18:24:48 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Print today's time
// struct timeval	tv;
// if	(gettimeofday(&tv, NULL))
// 	return (1);

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!is_valid_input(argc, argv))
		return (1);
	if (init_table(&table, argc, argv))
		return (1);
	for (int i = 0; i < ft_atoi(argv[1]); i++)
	{
		printf("Philo id: %d\n", table->philos[i].id);
		printf("Time to die: %zu\n", table->philos[i].time_to_die);
		printf("Time to eat: %zu\n", table->philos[i].time_to_eat);
		printf("Time to sleep: %zu\n", table->philos[i].time_to_sleep);
		printf("Must eat: %d\n", table->philos[i].must_eat);
		printf("\n");
	}
	for (int i = 0; i < ft_atoi(argv[1]); i++)
	{
		pthread_join(table->philos[i].thread, NULL);
	}
	return (0);
}
