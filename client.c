/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:28:13 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/23 20:45:06 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	test_pid_is_digit(char *argv, pid_t *pid_server)
{
	(*pid_server) = atoi(argv);
	if (kill(*pid_server, 0))
	{
		printf("Server PID error\n");
		exit(1);
	}
	printf("Server PID valid\n");
}

/* Send SIGUSR1 (= 0) if bit is 0 and SIGUSR2 (= 1) if bit is 1 */
void	send_bit(pid_t pid_server, int bit)
{
	if (bit)
		kill(pid_server, SIGUSR2);
	else
		kill(pid_server, SIGUSR1);
	usleep(1000);
}

void	send_char(pid_t pid_server, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		send_bit(pid_server, (c >> i) & 1);
		i++;
	}
}

void	send_msg(pid_t pid_server, char *message)
{
	int	i;

	i = 0;
	while (message[i])
		send_char(pid_server, message[i++]);
	send_char(pid_server, '\0');
	printf("Message sent!\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	char	*message;

	if (argc != 3)
	{
		printf("Usage: ./client <PID> <message>\n");
		printf("!! Handle error !!\n");
		return (1);
	}
	test_pid_is_digit(argv[1], &pid_server);
	printf("Client PID: %d\n", getpid());
	message = argv[2];
	printf("Send message '%s' to PID: %d\n", message, pid_server);
	send_msg(pid_server, message);
	return (0);
}
