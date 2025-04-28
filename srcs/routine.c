/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:23:19 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/28 13:17:15 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_simulation_running(t_table *table)
{
	int	dead_flag;
	int	eat_flag;

	pthread_mutex_lock(&table->table_lock);
	dead_flag = table->dead;
	eat_flag = table->everyone_have_eat_enough;
	pthread_mutex_unlock(&table->table_lock);
	return (!dead_flag && !eat_flag);
}

static void	*one_philo(t_philo *philo)
{
	if (!is_simulation_running(philo->table))
		return (NULL);
	print_action(philo, "is thinking");
	if (!is_simulation_running(philo->table))
		return (NULL);
	print_action(philo, "has taken a fork");
	if (!is_simulation_running(philo->table))
		return (NULL);
	ft_usleep(philo->table->time_to_die, philo->table);
	return (NULL);
}

static int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (!is_simulation_running(philo->table))
	{
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	if (!is_simulation_running(philo->table))
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	print_action(philo, "has taken a fork");
	return (0);
}

static int	eat(t_philo *philo)
{
	if (!is_simulation_running(philo->table))
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	print_action(philo, "is eating");
	ft_usleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_lock(&philo->table->table_lock);
	philo->time_last_eat = get_curr_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->table->table_lock);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->n_philo == 1)
		return (one_philo(philo));
	if (philo->id % 2 == 0)
		ft_usleep(1, philo->table);
	while (is_simulation_running(philo->table))
	{
		print_action(philo, "is thinking");
		if (take_forks(philo))
			break ;
		if (eat(philo))
			break ;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (!is_simulation_running(philo->table))
			break ;
		print_action(philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep, philo->table);
	}
	return (NULL);
}
