/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:05 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/16 18:02:03 by vblanc           ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;

	int				n_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				must_eat;

	size_t			time_start;
	size_t			time_last_eat;
	int				eat_count;
	int				*is_dead;

	pthread_t		thread;

	pthread_mutex_t	*m_l_fork;
	pthread_mutex_t	*m_r_fork;
	pthread_mutex_t	*m_eat;
	pthread_mutex_t	*m_dead;
}					t_philo;

typedef struct s_table
{
	int				dead;
	pthread_mutex_t	*m_eat;
	pthread_mutex_t	*m_dead;
	t_philo			*philos;
}					t_table;

/* --------------------- Libft --------------------- */

size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);

/* --------------------- Functions --------------------- */

int					init_table(t_table **table, int argc, char **argv);
void				*routine(void *arg);

/* --------------------- Utils --------------------- */

int					is_valid_input(int argc, char **argv);

#endif
