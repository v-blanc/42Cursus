/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:34:00 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/15 20:10:40 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>

extern char	**environ;

int			handle_heredoc(char *delim, const bool ex, t_context *ctx);
static bool	read_input(int fd, char *delim, const bool ex, t_context *ctx);
static bool	delim_reached(char **line, char *delim, int count, t_context *ctx);
static bool	print_line(int fd, char *line, const bool expand, t_context *ctx);
static bool	expander_heredoc(int fd, char *line, t_context *ctx);

int	handle_heredoc(char *delimiter, const bool expand, t_context *ctx)

{
	int	pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		return (-1);
	if (!read_input(pipe_fd[OUT_FD], delimiter, expand, ctx))
	{
		close(pipe_fd[OUT_FD]);
		close(pipe_fd[IN_FD]);
		return (-1);
	}
	close(pipe_fd[OUT_FD]);
	return (pipe_fd[IN_FD]);
}

static bool	read_input(int fd, char *delim, const bool ex, t_context *ctx)

{
	char	*line;
	int		count;

	count = 1;
	while (true)
	{
		write(3, "> ", 2);
		line = get_next_line(STDIN_FILENO, ctx);
		if (line && line[0] == '\n' && !line[1])
		{
			write(fd, "\n", 1);
			gc_free(line, ctx->head);
			count++;
			continue ;
		}
		if (delim_reached(&line, delim, count, ctx))
			break ;
		if (!print_line(fd, line, ex, ctx))
			return (false);
		gc_free(line, ctx->head);
		count++;
	}
	gc_free(line, ctx->head);
	return (true);
}

static bool	delim_reached(char **line, char *delim, int count, t_context *ctx)

{
	const size_t	delim_size = ft_strlen(delim);

	if (*line == NULL)
	{
		print(2, "minishell: warning: here-document at line %d ", count);
		print(2, "delimited by end-of-file (wanted `%s')\n", delim);
		return (true);
	}
	if (!ft_strncmp(*line, delim, delim_size) && (*line)[delim_size] == '\n')
	{
		gc_free(*line, ctx->head);
		return (true);
	}
	return (false);
}

static bool	print_line(int fd, char *line, const bool expand, t_context *ctx)

{
	if (expand)
	{
		if (!expander_heredoc(fd, line, ctx))
		{
			gc_free(line, ctx->head);
			return (false);
		}
	}
	else
		print(fd, "%s", line);
	return (true);
}

static bool	expander_heredoc(int fd, char *line, t_context *ctx)

{
	t_token	*tok;
	int		len_value_expanded;

	tok = NULL;
	if (tokenizer(&tok, line, &ctx))
		return (false);
	while (tok)
	{
		len_value_expanded = get_expand_len(tok->value, ctx);
		if (len_value_expanded < 0)
			return (false);
		if (expand_one_token(&tok->value, len_value_expanded, ctx))
			return (false);
		print(fd, "%s\n", tok->value);
		tok = tok->next;
	}
	return (true);
}
