/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:25:04 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/21 00:25:04 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sub_monitoring(t_table *table, int i, int *have_eaten_enough)
{
	pthread_mutex_lock(&table->table_lock);
	if (get_curr_time() - table->philos[i].time_last_eat > table->time_to_die)
	{
		print_action(&table->philos[i], "died");
		table->dead = 1;
		pthread_mutex_unlock(&table->table_lock);
		return (1);
	}
	if (table->must_eat != -1 && table->philos[i].eat_count == table->must_eat)
		(*have_eaten_enough)++;
	pthread_mutex_unlock(&table->table_lock);
	return (0);
}

void	*monitoring(void *arg)
{
	t_table	*table;
	int		have_eaten_enough;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		have_eaten_enough = 0;
		i = 0;
		while (i < table->n_philo)
		{
			if (sub_monitoring(table, i, &have_eaten_enough))
				return (NULL);
			i++;
		}
		if (have_eaten_enough == table->n_philo)
		{
			table->everyone_have_eat_enough = 1;
			return (NULL);
		}
		ft_usleep(1);
	}
	return (NULL);
}
