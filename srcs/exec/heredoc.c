/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:34:00 by yabokhar          #+#    #+#             */
/*   Updated: 2025/04/16 14:44:04 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>

static void	print_warning_eof(int count, const char *delimiter)
{
	print(2, "minishell: warning: here-document at line %d ", count);
	print(2, "delimited by end-of-file (wanted `%s')\n", delimiter);
}

int	handle_heredoc(const char *delimiter)

{
	int				pipe_fd[2];
	int				count;
	char			*line;
	const size_t	delimiter_length = ft_strlen(delimiter);

	if (pipe(pipe_fd) < 0)
		return (EXIT_FAILURE);
	count = 1;
	while (true)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line || (ft_strncmp(line, delimiter, delimiter_length) == 0
				&& line[delimiter_length] == '\n'))
		{
			if (!line)
				print_warning_eof(count, delimiter);
			break ;
		}
		write(pipe_fd[OUT_FD], line, ft_strlen(line));
		free(line);
		count++;
	}
	free(line);
	close(pipe_fd[OUT_FD]);
	return (pipe_fd[IN_FD]);
}
