/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:49:22 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/15 18:32:11 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_next_line(int fd, t_context *ctx)
{
	static char	buffer[FD_MAX + 1][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	line = duplicate_(buffer[fd], ctx);
	while (!string_contains_newline(buffer[fd]))
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[fd][bytes_read] = '\0';
		line = concatenate_(line, buffer[fd], ctx);
	}
	shift_(buffer[fd]);
	if (!line || !*line)
	{
		gc_free(line, ctx->head);
		return (NULL);
	}
	return (line);
}
