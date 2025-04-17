/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:08 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/17 05:01:48 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!is_valid_input(argc, argv))
		return (1);
	printf("Current time is: %zu\n", get_curr_time());
	if (init_table(&table, argc, argv))
		return (1);
	// for (int i = 0; i < ft_atoi(argv[1]); i++)
	// {
	// 	printf("Philo id: %d\n", table->philos[i].id);
	// 	printf("Time to die: %zu\n", table->philos[i].time_to_die);
	// 	printf("Time to eat: %zu\n", table->philos[i].time_to_eat);
	// 	printf("Time to sleep: %zu\n", table->philos[i].time_to_sleep);
	// 	printf("Must eat: %d\n", table->philos[i].must_eat);
	// 	printf("\n");
	// }
	// for (int i = 0; i < ft_atoi(argv[1]); i++)
	// {
	// 	pthread_join(table->philos[i].thread, NULL);
	// }
	return (0);
}
