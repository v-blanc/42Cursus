/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:05 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/17 04:58:32 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* --------------------- Libraries --------------------- */

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* --------------------- Variables --------------------- */

/* --------------------- Structures --------------------- */

typedef struct s_table	t_table;

typedef struct s_philo
{
	// Id variables
	int					id;
	pthread_t			thread;

	// Internal variables
	int					eat_count;
	size_t				time_start;
	size_t				time_last_eat;

	// Locks
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*table_lock;
	pthread_mutex_t		*write_lock;
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
	pthread_mutex_t		table_lock;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		*forks;
	t_philo				*philos;
};

/* --------------------- Libft --------------------- */

size_t					ft_strlen(const char *s);
int						ft_atoi(const char *str);

/* --------------------- Functions --------------------- */

int						init_table(t_table **table, int argc, char **argv);
void					*routine(void *arg);

/* --------------------- Utils --------------------- */

size_t					get_curr_time(void);
int						is_valid_input(int argc, char **argv);

#endif
