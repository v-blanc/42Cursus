#include "../../include/minishell.h"

extern char	**environ;

int	env(void)
{
	int	i;

	i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]);
	return (0);
}
