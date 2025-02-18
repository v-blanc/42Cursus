/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:12:33 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/18 18:32:01 by vblanc           ###   ########.fr       */
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
		write(1, "Error sending message\n", 22);
		exit(1);
	}
	usleep(500);
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
