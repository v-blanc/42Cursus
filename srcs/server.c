/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:21:54 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/05 12:46:11 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_data_server	g_data_serv;

static void	init_data_server(void)
{
	g_data_serv.bit_pos = 0;
	g_data_serv.curr_char = 0;
	g_data_serv.msg_index = 0;
	if (g_data_serv.msg)
		free(g_data_serv.msg);
	g_data_serv.msg = malloc(sizeof(char) * (BUFFER_SIZE + 1));
}

void	print_msg_received(siginfo_t *siginfo)
{
	char	*msg;

	msg = ft_itoa(siginfo->si_pid);
	write(1, "Message received from PID ", 27);
	write(1, msg, ft_intlen(siginfo->si_pid));
	write(1, "\n  '", 4);
	write(1, g_data_serv.msg, ft_strlen(g_data_serv.msg));
	write(1, "'\n", 2);
	free(msg);
}

static void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (sig == SIGUSR2)
		g_data_serv.curr_char |= (1 << g_data_serv.bit_pos);
	g_data_serv.bit_pos++;
	if (g_data_serv.bit_pos == 8)
	{
		if (g_data_serv.msg_index == BUFFER_SIZE - 1)
		{
			g_data_serv.msg = ft_addloc(g_data_serv.msg, BUFFER_SIZE);
			if (!g_data_serv.msg)
				exit(1);
		}
		g_data_serv.msg[g_data_serv.msg_index++] = g_data_serv.curr_char;
		if (g_data_serv.curr_char == '\0')
		{
			print_msg_received(siginfo);
			init_data_server();
			usleep(50);
			send_bit(siginfo->si_pid, 0);
		}
		g_data_serv.curr_char = 0;
		g_data_serv.bit_pos = 0;
	}
}

static void	set_signal_handler(struct sigaction sa)
{
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;
	char				*pid_str;

	init_data_server();
	pid = getpid();
	pid_str = ft_itoa(pid);
	write(1, "PID server: ", 13);
	write(1, pid_str, ft_intlen(pid));
	write(1, "\n", 1);
	free(pid_str);
	sa = (struct sigaction){0};
	set_signal_handler(sa);
	while (1)
		pause();
	return (0);
}
