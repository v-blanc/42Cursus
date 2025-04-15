#include "minishell.h"

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

char	*duplicate_(char *buffer)
{
	char	*duplicated_line;
	size_t	length;
	size_t	i;

	length = string_length(buffer);
	if (!length)
		return (NULL);
	duplicated_line = malloc(sizeof(char) * (length + 1));
	if (!duplicated_line)
		return (NULL);
	i = -1;
	while (++i < length)
		duplicated_line[i] = buffer[i];
	duplicated_line[i] = '\0';
	return (duplicated_line);
}

char	*concatenate_(char *line, char *buffer)
{
	char			*concatened_line;
	const size_t	total_length = string_length(line) + string_length(buffer);
	size_t			i;
	size_t			j;

	concatened_line = malloc(sizeof(char) * (total_length + 1));
	if (!concatened_line)
	{
		free(line);
		return (NULL);
	}
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
	free(line);
	return (concatened_line);
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
