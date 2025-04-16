/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:17:33 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/16 18:23:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_table **table, int id, int argc, char **argv)
{
	t_philo			*philo;
	struct timeval	tv;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	philo->id = id + 1;
	philo->n_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->must_eat = -1;
	if (argc == 6)
		philo->must_eat = ft_atoi(argv[5]);
	if (gettimeofday(&tv, NULL))
		return (1);
	philo->time_start = tv.tv_sec * 1000000 + tv.tv_usec;
	philo->time_last_eat = 0;
	philo->eat_count = 0;
	philo->is_dead = 0;
	philo->m_l_fork = (*table)->philos[id].m_l_fork;
	philo->m_r_fork = (*table)->philos[id].m_r_fork;
	philo->m_eat = (*table)->philos[id].m_eat;
	philo->m_dead = (*table)->philos[id].m_dead;
	if (pthread_create(&(*table)->philos[id].thread, NULL, &routine, &philo))
		return (1);
	(*table)->philos[id] = *philo;
	return (0);
}

int	init_table(t_table **table, int argc, char **argv)
{
	int	i;
	int	n_philo;

	*table = (t_table *)malloc(sizeof(t_table));
	if (!(*table))
		return (1);
	n_philo = ft_atoi(argv[1]);
	(*table)->philos = (t_philo *)malloc(sizeof(t_philo) * n_philo);
	if (!(*table)->philos)
		return (1);
	i = 0;
	while (i < n_philo)
	{
		if (init_philo(table, i, argc, argv))
			return (1);
		i++;
	}
	return (0);
}
