/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:21:54 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/19 05:24:09 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	curr_char = 0;
volatile sig_atomic_t	bit_pos = 0;

#define MAX_MESSAGE_LENGTH 256
volatile char msg[MAX_MESSAGE_LENGTH];
volatile sig_atomic_t msg_index = 0;

void	sig_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		curr_char |= (1 << bit_pos);
	}
	bit_pos++;
	if (bit_pos == 8)
	{
		if (curr_char == '\0')
		{
			msg[msg_index] = '\0';
			printf("Message received from PID: %s\n", msg);
			msg_index = 0;
		}
		else if (msg_index < MAX_MESSAGE_LENGTH - 1)
			msg[msg_index++] = curr_char;
		curr_char = 0;
		bit_pos = 0;
	}
}

// void	sig_handler(int sig)
// {
//     if (sig == SIGUSR1)
//         printf("Received SIGUSR1\n");
//     else if (sig == SIGUSR2)
//         printf("Received SIGUSR2\n");
// }

int	main(void)
{
	pid_t pid = getpid();
    char *msg[MAX_MESSAGE_LENGTH];
	printf("PID server: %d\n", pid);

	struct sigaction sa;
	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Waiting for signal from client...\n");
	while (1)
		pause();
	return (0);
}