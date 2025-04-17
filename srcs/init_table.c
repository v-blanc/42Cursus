/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:17:33 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/17 05:14:56 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philos(t_table *table)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(sizeof(t_philo) * table->n_philo);
	if (!philos)
		return (1);
	i = 0;
	while (i < table->n_philo)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].time_start = get_curr_time();
		philos[i].time_last_eat = philos[i].time_start;
		philos[i].l_fork = &table->forks[(i + 1) % table->n_philo];
		philos[i].r_fork = &table->forks[i];
		philos[i].table_lock = &table->table_lock;
		philos[i].write_lock = &table->write_lock;
		philos[i].table = table;
		i++;
	}
	table->philos = philos;
	return (0);
}

static int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (1);
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
	if (init_forks(*table))
		return (1);
	if (init_philos(*table))
		return (1);
	return (0);
}
