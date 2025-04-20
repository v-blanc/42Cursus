/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:08 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/20 18:43:50 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	print_init_info(t_table *table)
// {
// 	printf("Table: %p\n", table);
// 	printf("Number of philosophers: %d\n", table->n_philo);
// 	printf("Time to die: %zu\n", table->time_to_die);
// 	printf("Time to eat: %zu\n", table->time_to_eat);
// 	printf("Time to sleep: %zu\n", table->time_to_sleep);
// 	printf("Must eat: %d\n", table->must_eat);
// 	printf("Time start: %zu\n", table->time_start);
// 	printf("Table lock: %p\n", &table->table_lock);
// 	printf("Write lock: %p\n", &table->write_lock);
// 	printf("\n");
// 	for (int i = 0; i < table->n_philo; i++)
// 	{
// 		printf("Philo id: %d\n", table->philos[i].id);
// 		printf("Eat count: %d\n", table->philos[i].eat_count);
// 		printf("Time last eat: %zu\n", table->philos[i].time_last_eat);
// 		printf("Left fork: %p\n", table->philos[i].l_fork);
// 		printf("Right fork: %p\n", table->philos[i].r_fork);
// 		printf("Table: %p\n", table->philos[i].table);
// 		printf("\n");
// 	}
// }

static void	launch_philos(t_table *table)
{
	for (int i = 0; i < table->n_philo; i++)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine,
				&table->philos[i]))
		{
			clear_table(table, table->n_philo);
			return ;
		}
	}
	for (int i = 0; i < table->n_philo; i++)
		pthread_join(table->philos[i].thread, NULL);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!is_valid_input(argc, argv))
		return (1);
	table = NULL;
	if (init_table(&table, argc, argv))
		return (1);
	// print_init_info(table);
	launch_philos(table);
	clear_table(table, table->n_philo);
	return (0);
}
