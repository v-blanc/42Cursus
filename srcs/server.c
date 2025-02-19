/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:21:54 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/19 15:51:02 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_data_server	g_data_serv;

static void	init_data_server(pid_t curr_pid)
{
	g_data_serv.bit_pos = 0;
	g_data_serv.curr_char = 0;
	g_data_serv.msg_index = 0;
	g_data_serv.msg_len = 0;
	if (g_data_serv.curr_pid != 0 && curr_pid != 0)
		ft_printf("❌ Error receiving message from PID %d\n\n",
			g_data_serv.curr_pid);
	g_data_serv.curr_pid = curr_pid;
	if (g_data_serv.msg)
		free(g_data_serv.msg);
	g_data_serv.msg = NULL;
}

void	resize(t_data_server *data)
{
	char	*new_msg;

	new_msg = ft_calloc(data->msg_len + BUFFER_SIZE, sizeof(char));
	if (!new_msg)
	{
		free(data->msg);
		exit(1);
	}
	ft_memcpy(new_msg, data->msg, data->msg_len);
	free(data->msg);
	data->msg = new_msg;
	data->msg_len += BUFFER_SIZE;
}

static void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (siginfo->si_pid != g_data_serv.curr_pid)
		init_data_server(siginfo->si_pid);
	if (sig == SIGUSR2)
		g_data_serv.curr_char |= (1 << g_data_serv.bit_pos);
	g_data_serv.bit_pos++;
	if (g_data_serv.bit_pos == 8)
	{
		if (g_data_serv.msg_index + 1 >= g_data_serv.msg_len)
			resize(&g_data_serv);
		g_data_serv.msg[g_data_serv.msg_index++] = g_data_serv.curr_char;
		if (g_data_serv.curr_char == '\0')
		{
			ft_printf("✅ Message received from PID %d\n", siginfo->si_pid);
			ft_printf("  '%s'\n\n", g_data_serv.msg);
			init_data_server(0);
			if (siginfo->si_pid > 0)
				kill(siginfo->si_pid, SIGUSR1);
		}
		g_data_serv.curr_char = 0;
		g_data_serv.bit_pos = 0;
	}
	if (siginfo->si_pid > 0)
		kill(siginfo->si_pid, SIGUSR2);
}

static void	set_signal_handler(void)
{
	struct sigaction	sa;

	sa = (struct sigaction){0};
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	ft_printf("ℹ️  PID server: %d\n\n", getpid());
	init_data_server(0);
	set_signal_handler();
	while (1)
		pause();
	return (0);
}
