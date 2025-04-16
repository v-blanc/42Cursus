/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:23:19 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/16 18:25:21 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	// int		i;
	usleep(1000);
	philo = (t_philo *)arg;
	printf("routine\n");
	printf("Philo id: %d\n", philo->id);
	// i = 0;
	// while (i < 10)
	// {
	// 	printf("Try to eat\n");
	// 	printf("%zu %d is sleeping\n", get_time(), i);
	// 	i++;
	// }
	return (NULL);
}
