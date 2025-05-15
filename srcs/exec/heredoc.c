/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:34:00 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/15 18:15:31 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>

extern char	**environ;

static void	print_warning_eof(int count, const char *delimiter)
{
	print(2, "minishell: warning: here-document at line %d ", count);
	print(2, "delimited by end-of-file (wanted `%s')\n", delimiter);
}

int	expander_heredoc(int fd, char *line, t_context *ctx)
{
	t_token	*tok;
	int		len_value_expanded;

	tok = NULL;
	if (tokenizer(&tok, line, &ctx))
		return (1);
	while (tok)
	{
		len_value_expanded = get_expand_len(tok->value, ctx);
		if (len_value_expanded < 0)
			return (1);
		if (expand_one_token(&tok->value, len_value_expanded, ctx))
			return (1);
		print(fd, "%s\n", tok->value);
		tok = tok->next;
	}
	return (0);
}

int	handle_heredoc(const char *delimiter, const bool expand, t_context *ctx)

{
	int pipe_fd[2];
	int count;
	char *line;

	if (pipe(pipe_fd) < 0)
		return (EXIT_FAILURE);
	count = 1;
	while (true)
	{
		write(3, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line[0] == '\n' && !line[1])
		{
			print(pipe_fd[OUT_FD], "\n");
			continue ;
		}
		if (!line || (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
				&& line[ft_strlen(delimiter)] == '\n'))
		{
			if (!line)
				print_warning_eof(count, delimiter);
			break ;
		}
		if (expand)
			expander_heredoc(pipe_fd[OUT_FD], line, ctx);
		else
			print(pipe_fd[OUT_FD], "%s", line);
		free(line);
		count++;
	}
	return (free(line), close(pipe_fd[OUT_FD]), pipe_fd[IN_FD]);
}
