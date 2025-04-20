/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 04:19:06 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/20 19:06:17 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_curr_time();
	while ((get_curr_time() - start) < ms)
		usleep(100);
}

size_t	get_curr_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return (time.tv_sec * 1e3 + time.tv_usec * 1e-3);
}
