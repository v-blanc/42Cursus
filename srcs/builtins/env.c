#include "minishell.h"


extern char	**environ;

int	env(int fd, int args_count)
{
	int	i;

	if (args_count > 1)
	{
		print(fd, "env: too many arguments\n");
		return (0);
	}
	i = 0;
	while (environ[i])
		print(fd, "%s\n", environ[i++]);
	return (0);
}
