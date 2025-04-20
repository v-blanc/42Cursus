/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:17:33 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/21 00:22:39 by vblanc           ###   ########.fr       */
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
	table->philos = philos;
	i = 0;
	while (i < table->n_philo)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].time_last_eat = table->time_start;
		philos[i].l_fork = &table->forks[(i + 1) % table->n_philo];
		philos[i].r_fork = &table->forks[i];
		philos[i].table = table;
		i++;
	}
	return (0);
}

static int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			clear_table(table, i);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	sub_init_table(t_table **table)
{
	int	return_value;

	return_value = 1;
	if (pthread_mutex_init(&(*table)->table_lock, NULL))
		return_value = 1;
	else if (pthread_mutex_init(&(*table)->write_lock, NULL))
		pthread_mutex_destroy(&(*table)->table_lock);
	else if (init_forks(*table))
		return_value = 1;
	else if (init_philos(*table))
	{
		clear_table(*table, (*table)->n_philo);
		return (1);
	}
	else
		return_value = 0;
	if (return_value)
	{
		free((*table)->forks);
		free(*table);
	}
	return (return_value);
}

int	init_table(t_table **table, int argc, char **argv)
{
	*table = (t_table *)malloc(sizeof(t_table));
	if (!(*table))
		return (1);
	(*table)->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* ft_atoi(argv[1]));
	if (!(*table)->forks)
	{
		free(*table);
		return (1);
	}
	(*table)->n_philo = ft_atoi(argv[1]);
	(*table)->time_to_die = ft_atoi(argv[2]);
	(*table)->time_to_eat = ft_atoi(argv[3]);
	(*table)->time_to_sleep = ft_atoi(argv[4]);
	(*table)->must_eat = -1;
	if (argc == 6)
		(*table)->must_eat = ft_atoi(argv[5]);
	(*table)->time_start = get_curr_time();
	if ((*table)->time_start == 0)
		return (1);
	(*table)->dead = 0;
	(*table)->everyone_have_eat_enough = 0;
	(*table)->philos = NULL;
	return (sub_init_table(table));
}

void	clear_table(t_table *table, int n_forks)
{
	int	i;

	i = 0;
	while (i < n_forks)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->table_lock);
	pthread_mutex_destroy(&table->write_lock);
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	free(table);
}
