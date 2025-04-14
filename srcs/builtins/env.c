#include "../../include/minishell.h"

extern char	**environ;

int	env(int args_count)
{
	int	i;

	if (args_count > 1)
	{
		printf("env: too many arguments\n");
		return (0);
	}
	i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]);
	return (0);
}
