/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:34:00 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/18 19:55:49 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "utils.h"

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
	if (!read_input(pipe_fd[STDOUT_FILENO], delimiter, expand, ctx))
	{
		close(pipe_fd[STDOUT_FILENO]);
		close(pipe_fd[STDIN_FILENO]);
		return (-1);
	}
	close(pipe_fd[STDOUT_FILENO]);
	return (pipe_fd[STDIN_FILENO]);
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
		if (errno == EINTR)
			return (true);
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
	t_gc	*temp_head;
	int		len_expand;

	temp_head = NULL;
	tok = NULL;
	if (heredoc_tokenizer(&tok, line, &temp_head))
	{
		gc_free_all(&temp_head);
		return (false);
	}
	while (tok)
	{
		len_expand = get_expand_len(tok->value, ctx);
		if (len_expand < 0 || expand_one_token(&tok->value, len_expand, ctx))
		{
			gc_free_all(&temp_head);
			return (false);
		}
		print(fd, "%s\n", tok->value);
		tok = tok->next;
	}
	gc_free_all(&temp_head);
	return (true);
}
