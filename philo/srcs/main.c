/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:08 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/21 00:25:37 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	launch_philos(t_table *table, pthread_t monitor)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine,
				&table->philos[i]))
		{
			clear_table(table, table->n_philo);
			return ;
		}
		i++;
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < table->n_philo)
		pthread_join(table->philos[i++].thread, NULL);
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
