#include "../../include/minishell.h"

int	pwd(int fd)
{
	char	path[PATH_MAX];

	if (getcwd(path, PATH_MAX) == NULL)
	{
		print(2, "getcwd: %s\n", strerror(errno));
		return (1);
	}
	else
		print(fd, "%s\n", path);
	return (0);
}
