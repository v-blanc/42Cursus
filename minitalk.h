/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:24:05 by vblanc            #+#    #+#             */
/*   Updated: 2024/12/04 17:31:23 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

# define MAX_MESSAGE_LENGTH 256

typedef struct s_data_server
{
	sig_atomic_t	bit_pos;
	sig_atomic_t	curr_char;
	char			msg[MAX_MESSAGE_LENGTH];
	sig_atomic_t	msg_index;
}					t_data_server;

/* utils.c */

size_t				ft_strlen(const char *s);
int					ft_intlen(int n);
char				*ft_itoa(int n);

#endif
