/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:08 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/21 00:23:25 by vblanc           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_table		*table;
	pthread_t	monitor;

	if (!is_valid_input(argc, argv))
		return (1);
	table = NULL;
	if (init_table(&table, argc, argv))
		return (1);
	pthread_create(&monitor, NULL, &monitoring, table);
	launch_philos(table, monitor);
	clear_table(table, table->n_philo);
	return (0);
}
