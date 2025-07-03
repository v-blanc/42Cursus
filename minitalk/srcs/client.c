/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:28:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/03/03 16:53:04 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

sig_atomic_t	g_sever_ready;

static void	test_pid_validity(char *argv, pid_t *pid_server)
{
	(*pid_server) = atoi(argv);
	if (kill(*pid_server, 0) || *pid_server < 1)
	{
		ft_printf("ℹ️  Server PID: %d (invalid ❌)\n", *pid_server);
		exit(1);
	}
	ft_printf("ℹ️  Server PID: %d (valid ✅)\n", *pid_server);
}

static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("✅ Server confirmed message reception!\n");
		g_sever_ready = 1;
	}
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
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <message>\n");
		return (1);
	}
	test_pid_validity(argv[1], &pid_server);
	ft_printf("ℹ️  Client PID: %d\n⏳ Sending message '%s'...\n", getpid(),
		argv[2]);
	set_signal_handler();
	send_msg(pid_server, argv[2]);
	while (!g_sever_ready)
		continue ;
	return (0);
}
