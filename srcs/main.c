/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:08 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/24 15:36:43 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	launch_philos(t_table *table, pthread_t monitor)
{
	int	i;

	if (pthread_create(&monitor, NULL, &monitoring, table))
		return ;
	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine,
				&table->philos[i]))
		{
			while (--i >= 0)
				pthread_join(table->philos[i].thread, NULL);
			pthread_join(monitor, NULL);
			return ;
		}
		i++;
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < table->n_philo)
		pthread_join(table->philos[i++].thread, NULL);
	return ;
}

int	main(int argc, char **argv)
{
	t_table		*table;
	pthread_t	monitor;
	int			return_flag;

	if (!is_valid_input(argc, argv))
		return (1);
	table = NULL;
	return_flag = init_table(&table, argc, argv);
	if (return_flag == 1)
		return (1);
	else if (return_flag == 2)
	{
		free(table->forks);
		free(table);
		return (1);
	}
	monitor = 0;
	launch_philos(table, monitor);
	clear_table(table, table->n_philo);
	return (0);
}
