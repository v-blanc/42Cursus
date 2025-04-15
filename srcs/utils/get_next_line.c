#include "minishell.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX + 1][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	line = duplicate_(buffer[fd]);
	while (!string_contains_newline(buffer[fd]))
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[fd][bytes_read] = '\0';
		line = concatenate_(line, buffer[fd]);
	}
	shift_(buffer[fd]);
	if (!line || !*line)
	{
		gc_free(line, NULL);
		return (NULL);
	}
	return (line);
}
