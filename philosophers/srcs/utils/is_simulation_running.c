/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_simulation_running.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:05:01 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/28 14:05:08 by vblanc           ###   ########.fr       */
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
