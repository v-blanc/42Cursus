/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:05 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/28 13:16:44 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* --------------------- Libraries --------------------- */

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/* --------------------- Structures --------------------- */

typedef struct s_table	t_table;

typedef struct s_philo
{
	// Id variables
	int					id;
	pthread_t			thread;

	// Internal variables
	int					eat_count;
	size_t				time_last_eat;

	// Locks
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	t_table				*table;
}						t_philo;

struct					s_table
{
	// Input variables
	int					n_philo;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					must_eat;

	// Internal variables
	size_t				time_start;
	int					dead;
	int					everyone_have_eat_enough;
	pthread_mutex_t		table_lock;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		*forks;
	t_philo				*philos;
};

/* --------------------- Functions --------------------- */

int						init_table(t_table **table, int argc, char **argv);
void					clear_table(t_table *table, int n_forks);
void					*monitoring(void *arg);
int						is_simulation_running(t_table *table);
void					*routine(void *arg);

/* --------------------- Utils --------------------- */

size_t					ft_strlen(const char *s);
int						ft_atoi(const char *str);
int						is_valid_input(int argc, char **argv);
void					ft_usleep(size_t ms, t_table *table);
size_t					get_curr_time(void);
void					print_action(t_philo *philo, const char *msg);

#endif
