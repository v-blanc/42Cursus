/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:11:29 by vblanc            #+#    #+#             */
/*   Updated: 2024/12/04 16:43:00 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_sub_read_file(int fd, char **buffer, char *tmp)
{
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (1);
		tmp[bytes_read] = '\0';
		if (ft_strjoin_custom(buffer, tmp))
			return (1);
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
	return (0);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*tmp;

	tmp = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free(buffer);
		return (NULL);
	}
	if (ft_sub_read_file(fd, &buffer, tmp))
	{
		free(tmp);
		free(buffer);
		return (NULL);
	}
	free(tmp);
	return (buffer);
}

static int	ft_get_line(char *buffer, char **line)
{
	size_t	i;

	i = 0;
	if (!buffer[i])
	{
		*line = NULL;
		return (0);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	(*line) = (char *)ft_calloc(i + 2, sizeof(char));
	if (!(*line))
		return (1);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		(*line)[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		(*line)[i++] = '\n';
	return (0);
}

static char	*ft_new_buffer(char *buffer)
{
	size_t	line_len;
	size_t	i;
	char	*cpy;

	line_len = 0;
	while (buffer[line_len] && buffer[line_len] != '\n')
		line_len++;
	if (!buffer[line_len])
	{
		free(buffer);
		return (NULL);
	}
	cpy = (char *)ft_calloc((ft_strlen(buffer) - line_len + 1), sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (buffer[++line_len])
		cpy[i++] = buffer[line_len];
	cpy[i] = '\0';
	free(buffer);
	return (cpy);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	if (ft_get_line(buffer, &line))
	{
		free(buffer);
		return (NULL);
	}
	buffer = ft_new_buffer(buffer);
	return (line);
}
