/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:24:57 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/21 00:24:58 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, const char *msg)
{
	size_t	time;

	pthread_mutex_lock(&philo->table->write_lock);
	time = (get_curr_time() - philo->table->time_start);
	printf("%zu %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->table->write_lock);
}
