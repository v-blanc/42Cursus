/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:21:54 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/23 20:43:07 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data_server	g_data_serv;

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (sig == SIGUSR2)
	{
		g_data_serv.curr_char |= (1 << g_data_serv.bit_pos);
	}
	g_data_serv.bit_pos++;
	if (g_data_serv.bit_pos == 8)
	{
		if (g_data_serv.curr_char == '\0')
		{
			g_data_serv.msg[g_data_serv.msg_index] = '\0';
			printf("Message received from PID %d:\n", siginfo->si_pid);
			printf("  '%s'\n", g_data_serv.msg);
			g_data_serv.msg_index = 0;
		}
		else if (g_data_serv.msg_index < MAX_MESSAGE_LENGTH - 1)
		{
			g_data_serv.msg[g_data_serv.msg_index++] = g_data_serv.curr_char;
		}
		g_data_serv.curr_char = 0;
		g_data_serv.bit_pos = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	g_data_serv.bit_pos = 0;
	g_data_serv.curr_char = 0;
	g_data_serv.msg_index = 0;
	memset(g_data_serv.msg, 0, sizeof(g_data_serv.msg));
	pid = getpid();
	printf("PID server: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Waiting for signal from client...\n");
	while (1)
		pause();
	return (0);
}
