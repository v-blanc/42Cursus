/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:08 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/20 23:46:23 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	launch_philos(t_table *table, pthread_t monitor)
{
	for (int i = 0; i < table->n_philo; i++)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine,
				&table->philos[i]))
		{
			clear_table(table, table->n_philo);
			return ;
		}
	}
	pthread_join(monitor, NULL);
	for (int i = 0; i < table->n_philo; i++)
		pthread_join(table->philos[i].thread, NULL);
}

static int	init_time_start(t_table *table)
{
	int	i;

	table->time_start = get_curr_time();
	if (table->time_start == 0)
		return (1);
	i = 0;
	while (i < table->n_philo)
		table->philos[i++].time_last_eat = table->time_start;
	return (0);
}

int	main(int argc, char **argv)
{
	t_table		*table;
	pthread_t	monitor;

	if (!is_valid_input(argc, argv))
		return (1);
	table = NULL;
	if (init_table(&table, argc, argv))
		return (1);
	if (init_time_start(table))
		return (1);
	pthread_create(&monitor, NULL, &monitoring, table);
	launch_philos(table, monitor);
	clear_table(table, table->n_philo);
	return (0);
}
