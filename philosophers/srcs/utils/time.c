/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 04:19:06 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/01 14:02:45 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(size_t ms, t_table *table)
{
	size_t	start;
	size_t	current;

	start = get_curr_time();
	current = get_curr_time();
	while ((current - start) < ms)
	{
		if ((current - start) % 500 == 0)
		{
			if (!is_simulation_running(table))
				return ;
		}
		current = get_curr_time();
		usleep(100);
	}
}

size_t	get_curr_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return (time.tv_sec * 1e3 + time.tv_usec * 1e-3);
}
