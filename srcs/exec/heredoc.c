/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:34:00 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/12 17:58:51 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>

extern char **environ;

static void	print_warning_eof(int count, const char *delimiter)
{
	print(2, "minishell: warning: here-document at line %d ", count);
	print(2, "delimited by end-of-file (wanted `%s')\n", delimiter);
}

void	expand_vars(int fd, const char *input)

{
	char	var_name[256];
	char	*var;
	char	*value;

	while (*input)
	{
		if (*input == '$' && (ft_isalpha(input[1]) || input[1] == '_'))
		{
			var = var_name;
			input++;
			while (ft_isalnum(*input) || *input == '_')
				*var++ = *input++;
			*var = '\0';
			value = getenv(var_name);
			if (value)
				print(fd, "%s", value);
		}
		else
		{
			write(fd, input, 1);
			input++;
		}
	}

}

int	handle_heredoc(const char *delimiter, const bool expand)

{
	int				pipe_fd[2];
	int				count;
	char			*line;

	if (pipe(pipe_fd) < 0)
		return (EXIT_FAILURE);
	count = 1;
	while (true)
	{
		write(3, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line || (ft_strncmp(line, delimiter, ft_strlen(line) - 1) == 0))
		{
			if (!line)
				print_warning_eof(count, delimiter);
			break ;
		}
		if (expand)
			expand_vars(pipe_fd[OUT_FD], line);
		else
			print(pipe_fd[OUT_FD], "%s", line);
		free(line);
		count++;
	}
	free(line);
	close(pipe_fd[OUT_FD]);
	return (pipe_fd[IN_FD]);
}
