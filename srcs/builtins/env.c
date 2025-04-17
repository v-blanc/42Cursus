#include "minishell.h"

extern char	**environ;

static int	print_error(char *argument, int error, int status)

{
	print(2, "env: ‘%s’: %s", argument, strerror(error));
	return (status);
}

int	env(int fd, char **arguments)
{
	struct stat	buffer;
	size_t		i;

	i = 0;
	while (arguments[i] && ft_strcmp(arguments[i], "env") == 0)
		i++;
	while (arguments[i])
	{
		if (stat(arguments[i], &buffer) < 0)
			return (print_error(arguments[i], errno, 127));
		if (!(buffer.st_mode & S_IEXEC))
			return (print_error(arguments[i], EACCES, 126));
		i++;
	}
	i = -1;
	while (environ[++i])
		print(fd, "%s\n", environ[i]);
	return (0);
}
