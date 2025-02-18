/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:28:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/18 18:13:57 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int			g_sever_ready;

static void	test_pid_validity(char *argv, pid_t *pid_server)
{
	(*pid_server) = atoi(argv);
	if (kill(*pid_server, 0))
	{
		ft_printf("Server PID: %d (invalid)\n", *pid_server);
		exit(1);
	}
	ft_printf("Server PID: %d (valid)\n", *pid_server);
}

static void	sig_handler(int sig)
{
	(void)sig;
	write(1, "Server confirmed message reception!\n", 37);
	g_sever_ready = 1;
}

static void	set_signal_handler(void)
{
	struct sigaction	sa;

	g_sever_ready = 0;
	sa = (struct sigaction){0};
	sa.sa_flags = 0;
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;

	if (argc != 3)
	{
		write(1, "Usage: ./client <PID> <message>\n", 33);
		return (1);
	}
	test_pid_validity(argv[1], &pid_server);
	ft_printf("Client PID: %d\nSending message '%s'...\n", getpid(), argv[2]);
	set_signal_handler();
	send_msg(pid_server, argv[2]);
	while (!g_sever_ready)
		pause();
	return (0);
}
