#include "../../include/minishell.h"

// TODO: handle errors (errno) from getcwd ?
int	pwd(void)
{
	char	path[PATH_MAX];

	if (getcwd(path, PATH_MAX) == NULL)
	{
		printf("getcwd error\n");
		return (1);
	}
	else
		printf("%s\n", path);
	return (0);
}

// int	main(void)
// {
// 	pwd();
// 	return (0);
// }
