#include "../../include/minishell.h"

extern char	**environ;

static int	ft_strlen_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static void	sort_environ_indexes(int *environ_indexes)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (environ[i])
	{
		j = i + 1;
		while (environ[j])
		{
			if (ft_strncmp(environ[environ_indexes[i]],
					environ[environ_indexes[j]], ft_strlen(environ[i])) > 0)
			{
				tmp = environ_indexes[i];
				environ_indexes[i] = environ_indexes[j];
				environ_indexes[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	get_environ_sorted_indexes(int **environ_indexes)
{
	int	i;

	(*environ_indexes) = (int *)malloc(sizeof(int) * ft_strlen_array(environ));
	if (!(*environ_indexes))
		return (printf("malloc error\n"), 1);
	i = -1;
	while (environ[++i])
		(*environ_indexes)[i] = i;
	sort_environ_indexes(*environ_indexes);
	return (0);
}

int	export(char *name)
{
	int	*environ_indexes;
	int	i;

	if (name == NULL || name[0] == '\0')
	{
		environ_indexes = NULL;
		if (get_environ_sorted_indexes(&environ_indexes))
			return (1);
		i = 0;
		while (environ[i])
		{
			if (ft_strncmp(environ[environ_indexes[i]], "_=", 2) != 0)
				printf("declare -x %s\n", environ[environ_indexes[i]]);
			i++;
		}
		free(environ_indexes);
	}
    //TODO: implement `export var_name`
	return (0);
}
