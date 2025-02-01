/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:28:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/01 17:50:58 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	test_pid_validity(char *argv, pid_t *pid_server)
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

/* Send SIGUSR1 (= 0) if bit is 0 and SIGUSR2 (= 1) if bit is 1 */
void	send_bit(pid_t pid_server, int bit)
{
	int	sig_to_send;

	if (bit)
		sig_to_send = SIGUSR2;
	else
		sig_to_send = SIGUSR1;
	if (kill(pid_server, sig_to_send))
	{
		write(1, "Error sending message\n", 22);
		exit(1);
	}
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
	write(1, "Message sent!\n", 15);
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	char	*pid_str;
	char	*message;

	if (argc != 3)
	{
		write(1, "Usage: ./client <PID> <message>\n", 33);
		write(1, "!! Handle error !!\n", 19);
		return (1);
	}
	test_pid_validity(argv[1], &pid_server);
	pid_str = ft_itoa(getpid());
	write(1, "Client PID: ", 13);
	write(1, pid_str, ft_intlen(getpid()));
	write(1, "\n", 1);
	free(pid_str);
	message = argv[2];
	write(1, "Sending message '", 18);
	write(1, message, ft_strlen(message));
	write(1, "'...\n", 5);
	send_msg(pid_server, message);
	return (0);
}
