#include "../../include/minishell.h"

// TODO: handle errors (errno) from getcwd ?
int	pwd(int fd)
{
	char	path[PATH_MAX];

	if (getcwd(path, PATH_MAX) == NULL)
	{
		print(2, "getcwd error\n");
		return (1);
	}
	else
		print(fd, "%s\n", path);
	return (0);
}
