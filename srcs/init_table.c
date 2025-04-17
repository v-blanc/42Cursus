/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:17:33 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/17 05:06:33 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * table->n_philo);
	if (!philo)
		return (1);
	i = 0;
	while (i < table->n_philo)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = 0;
		philo[i].time_start = get_curr_time();
		philo[i].time_last_eat = philo[i].time_start;
		philo[i].l_fork = &table->forks[(i + 1) % table->n_philo];
		philo[i].r_fork = &table->forks[i];
		philo[i].table_lock = &table->table_lock;
		philo[i].write_lock = &table->write_lock;
		philo[i].table = table;
		i++;
	}
	return (0);
}

int	init_table(t_table **table, int argc, char **argv)
{
	*table = (t_table *)malloc(sizeof(t_table));
	if (!(*table))
		return (1);
	(*table)->philos = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	(*table)->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* ft_atoi(argv[1]));
	if (!(*table)->philos || !(*table)->forks)
		return (1);
	(*table)->n_philo = ft_atoi(argv[1]);
	(*table)->time_to_die = ft_atoi(argv[2]);
	(*table)->time_to_eat = ft_atoi(argv[3]);
	(*table)->time_to_sleep = ft_atoi(argv[4]);
	(*table)->must_eat = -1;
	if (argc == 6)
		(*table)->must_eat = ft_atoi(argv[5]);
	if (pthread_mutex_init(&(*table)->table_lock, NULL)
		|| pthread_mutex_init(&(*table)->write_lock, NULL))
		return (1);
	if (init_philo(*table))
		return (1);
	return (0);
}
