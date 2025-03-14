#include "../include/minishell.h"

extern char	**environ;

int	ft_setenv(char *name, char *value)
{
	int	i;
	int	j;
	int	len_name;
	int	len_value;

	if (name == NULL || value == NULL)
		return (1);
	len_name = ft_strlen(name);
	len_value = ft_strlen(value);
	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], name, len_name))
		{
			j = -1;
			while (++j < len_value)
				environ[i][j + len_name + 1] = value[j];
			environ[i][len_name + len_value + 1] = '\0';
			return (0);
		}
		i++;
	}
	return (1);
}
