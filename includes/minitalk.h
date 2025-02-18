/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:24:05 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/12 18:31:07 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/include/ft_printf.h"
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
	sig_atomic_t	msg_index;
	sig_atomic_t	msg_len;
	char			*msg;
}					t_data_server;

/* utils.c */

void				resize(t_data_server *data);
void				send_bit(pid_t pid_dest, int bit);
void				send_msg(pid_t pid_dest, char *message);

#endif
