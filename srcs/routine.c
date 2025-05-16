/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:23:19 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/16 12:13:24 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static void	take_forks_loop(t_philo *philo, char type)
{
	int				*fork_state;
	pthread_mutex_t	*fork;

	if (type == 'l')
	{
		fork_state = philo->l_fork_state;
		fork = philo->l_fork;
	}
	else
	{
		fork_state = philo->r_fork_state;
		fork = philo->r_fork;
	}
	while (is_simulation_running(philo->table))
	{
		pthread_mutex_lock(fork);
		if (*fork_state == 0)
		{
			*fork_state = 1;
			pthread_mutex_unlock(fork);
			break ;
		}
		pthread_mutex_unlock(fork);
		usleep(50);
	}
}

static int	take_forks(t_philo *philo)
{
	take_forks_loop(philo, 'l');
	if (!is_simulation_running(philo->table))
		return (1);
	print_action(philo, "has taken a fork");
	take_forks_loop(philo, 'r');
	if (!is_simulation_running(philo->table))
		return (1);
	print_action(philo, "has taken a fork");
	return (0);
}

static int	eat(t_philo *philo)
{
	if (!is_simulation_running(philo->table))
		return (1);
	print_action(philo, "is eating");
	ft_usleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_lock(philo->l_fork);
	*(philo->l_fork_state) = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	*(philo->r_fork_state) = 0;
	pthread_mutex_unlock(philo->r_fork);
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
	while (get_curr_time() <= philo->table->time_start)
		usleep(100);
	if (philo->table->n_philo == 1)
		return (one_philo(philo));
	if (philo->id % 2 == 0)
		ft_usleep(4, philo->table);
	while (is_simulation_running(philo->table))
	{
		print_action(philo, "is thinking");
		if (philo->table->must_eat != -1
			&& philo->eat_count >= philo->table->must_eat)
			break ;
		if (take_forks(philo))
			break ;
		if (eat(philo))
			break ;
		if (!is_simulation_running(philo->table))
			break ;
		print_action(philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep, philo->table);
	}
	return (NULL);
}
