/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:23:19 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/20 23:44:35 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_simulation_running(t_philo *philo)
{
	int	dead_flag;
	int	eat_flag;

	pthread_mutex_lock(&philo->table->table_lock);
	dead_flag = philo->table->dead;
	eat_flag = (philo->eat_count < philo->table->must_eat);
	pthread_mutex_unlock(&philo->table->table_lock);
	return (!dead_flag && eat_flag);
}

static void	*one_philo(t_philo *philo)
{
	if (!is_simulation_running(philo))
		return (NULL);
	print_action(philo, "is thinking");
	if (!is_simulation_running(philo))
		return (NULL);
	print_action(philo, "has taken a fork");
	if (!is_simulation_running(philo))
		return (NULL);
	ft_usleep(philo->table->time_to_die);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->n_philo == 1)
		return (one_philo(philo));
	if (philo->id % 2 == 0)
		usleep(100);
	while (is_simulation_running(philo))
	{
		if (!is_simulation_running(philo))
			break ;
		print_action(philo, "is thinking");
		pthread_mutex_lock(philo->l_fork);
		if (!is_simulation_running(philo))
		{
			pthread_mutex_unlock(philo->l_fork);
			break ;
		}
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		if (!is_simulation_running(philo))
		{
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
			break ;
		}
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->table->table_lock);
		philo->time_last_eat = get_curr_time();
		philo->eat_count++;
		pthread_mutex_unlock(&philo->table->table_lock);
		if (!is_simulation_running(philo))
		{
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
			break ;
		}
		print_action(philo, "is eating");
		ft_usleep(philo->table->time_to_eat);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (!is_simulation_running(philo))
			break ;
		print_action(philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep);
	}
	return (NULL);
}
