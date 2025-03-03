/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:12:33 by vblanc            #+#    #+#             */
/*   Updated: 2025/03/03 16:53:01 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_bit(pid_t pid_dest, int bit)
{
	int	sig_to_send;

	if (bit)
		sig_to_send = SIGUSR2;
	else
		sig_to_send = SIGUSR1;
	if (kill(pid_dest, sig_to_send))
	{
		ft_printf("Error sending message\n");
		exit(1);
	}
	sleep(1);
}

void	send_msg(pid_t pid_dest, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			send_bit(pid_dest, (message[i] >> j) & 1);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		send_bit(pid_dest, 0);
		j++;
	}
}
