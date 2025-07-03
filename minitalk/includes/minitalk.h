/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:24:05 by vblanc            #+#    #+#             */
/*   Updated: 2025/03/03 16:52:57 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/include/ft_printf.h"
# include "./libft/libft.h"
# include <signal.h>
# include <sys/types.h>

# define BUFFER_SIZE 256

typedef struct s_data_server
{
	sig_atomic_t	bit_pos;
	sig_atomic_t	curr_char;
	sig_atomic_t	msg_index;
	sig_atomic_t	msg_len;
	sig_atomic_t	curr_pid;
	char			*msg;
}					t_data_server;

/* client_utils.c */

void				send_bit(pid_t pid_dest, int bit);
void				send_msg(pid_t pid_dest, char *message);

#endif
