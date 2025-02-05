/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:24:05 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/05 12:27:16 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include <signal.h>
# include <stdio.h> //TODO: remove
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFFER_SIZE 256

typedef struct s_data_server
{
	sig_atomic_t	bit_pos;
	sig_atomic_t	curr_char;
	char			*msg;
	sig_atomic_t	msg_index;
}					t_data_server;

/* utils.c */

char				*ft_addloc(char *str, int n);
void				send_bit(pid_t pid_dest, int bit);
void				send_msg(pid_t pid_dest, char *message);

#endif
