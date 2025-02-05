/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:28:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/05 12:59:14 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// OK
static void	test_pid_validity(char *argv, pid_t *pid_server)
{
	(*pid_server) = atoi(argv);
	if (kill(*pid_server, 0))
	{
		write(1, "Server PID: ", 13);
		write(1, argv, ft_strlen(argv));
		write(1, " (invalid)\n", 12);
		exit(1);
	}
	write(1, "Server PID: ", 13);
	write(1, argv, ft_strlen(argv));
	write(1, " (valid)\n", 10);
}

// OK
static void	print_client_msg(char *msg)
{
	char	*pid_str;

	pid_str = ft_itoa(getpid());
	if (!pid_str)
		exit(1);
	write(1, "Client PID: ", 13);
	write(1, pid_str, ft_intlen(getpid()));
	write(1, "\n", 1);
	free(pid_str);
	write(1, "Sending message '", 18);
	write(1, msg, ft_strlen(msg));
	write(1, "'...\n", 5);
}

static void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)context;
	if (siginfo->si_pid == getpid())
	{
		write(1, "Message sent!\n", 15);
		exit(0);
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

int	main(int argc, char **argv)
{
	pid_t				pid_server;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "Usage: ./client <PID> <message>\n", 33);
		write(1, "!! Handle error !!\n", 19);
		return (1);
	}
	test_pid_validity(argv[1], &pid_server);
	print_client_msg(argv[2]);
	send_msg(pid_server, argv[2]);
	sa = (struct sigaction){0};
	set_signal_handler(sa);
	while (1)
		pause();
	return (0);
}
