/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:21:54 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/18 18:15:13 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_data_server	g_data_serv;

static void	init_data_server(void)
{
	g_data_serv.bit_pos = 0;
	g_data_serv.curr_char = 0;
	g_data_serv.msg_index = 0;
	g_data_serv.msg_len = 0;
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
	(void)siginfo;
	(void)context;
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
			ft_printf("Message received from PID %d\n", siginfo->si_pid);
			ft_printf("  '%s'\n", g_data_serv.msg);
			init_data_server();
			if (siginfo->si_pid > 0)
			{
				kill(siginfo->si_pid, SIGUSR1);
			}
		}
		g_data_serv.curr_char = 0;
		g_data_serv.bit_pos = 0;
	}
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
	ft_printf("PID server: %d\n", getpid());
	init_data_server();
	set_signal_handler();
	while (1)
		pause();
	return (0);
}
