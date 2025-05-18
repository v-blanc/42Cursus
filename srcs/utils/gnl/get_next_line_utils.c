/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:49:16 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/18 14:31:31 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	string_length(const char *s)
{
	size_t	length;

	length = 0;
	while (s && s[length] && s[length] != '\n')
		length++;
	if (s && s[length] == '\n')
		length++;
	return (length);
}

char	*duplicate_(char *buffer, t_context *ctx)
{
	char	*duplicated_line;
	size_t	length;
	size_t	i;

	length = string_length(buffer);
	if (!length)
		return (NULL);
	duplicated_line = gc_malloc(sizeof(char) * (length + 1), ctx->head);
	if (!duplicated_line)
		return (NULL);
	i = -1;
	while (++i < length)
		duplicated_line[i] = buffer[i];
	duplicated_line[i] = '\0';
	return (duplicated_line);
}

char	*concatenate_(char *line, char *buffer, t_context *ctx)
{
	char			*concatened_line;
	const size_t	total_length = string_length(line) + string_length(buffer);
	size_t			i;
	size_t			j;

	concatened_line = gc_malloc(sizeof(char) * (total_length + 1), ctx->head);
	if (!concatened_line)
		return (gc_free(line, ctx->head), NULL);
	i = 0;
	j = 0;
	if (line)
	{
		while (line[j])
			concatened_line[i++] = line[j++];
	}
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
		concatened_line[i++] = buffer[j++];
	if (buffer[j] == '\n' && i < total_length)
	{
		concatened_line[i++] = '\n';
		j++;
	}
	concatened_line[i] = '\0';
	return (gc_free(line, ctx->head), concatened_line);
}

void	shift_(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
}

bool	string_contains_newline(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (true);
		buffer++;
	}
	return (false);
}
