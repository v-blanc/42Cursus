#include "../../include/minishell.h"

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
	duplicated_line = gc_malloc(length + 1, NULL);
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

	concatened_line = gc_malloc(total_length + 1, NULL);
	if (!concatened_line)
	{
		gc_free(line, NULL);
		return (NULL);
	}
	i = -1;
	while (line && line[++i])
		concatened_line[i] = line[i];
	while (*buffer && *buffer != '\n')
		concatened_line[i++] = *buffer++;
	if (*buffer == '\n')
		concatened_line[i++] = '\n';
	concatened_line[i] = '\0';
	gc_free(line, NULL);
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
