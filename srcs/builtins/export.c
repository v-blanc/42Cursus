#include "../../include/minishell.h"

extern char	**environ;

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

static int	get_environ_sorted_indexes(int **environ_indexes,
		t_garbage_collector **head)
{
	int	i;
	int	len_environ;

	len_environ = ft_strlen_array(environ);
	(*environ_indexes) = (int *)gc_malloc(sizeof(int) * len_environ, head);
	if (!(*environ_indexes))
		return (1);
	i = -1;
	while (environ[++i])
		(*environ_indexes)[i] = i;
	sort_environ_indexes(*environ_indexes);
	return (0);
}

int	export(char *name, char *value, t_garbage_collector **head)
{
	int	*environ_indexes;
	int	i;

	if (name == NULL || name[0] == '\0')
	{
		environ_indexes = NULL;
		if (get_environ_sorted_indexes(&environ_indexes, head))
			return (1);
		i = 0;
		while (environ[i])
		{
			if (ft_strncmp(environ[environ_indexes[i]], "_=", 2) != 0)
				// Can add "declare -x" before
				printf("%s\n", environ[environ_indexes[i]]);
			i++;
		}
		gc_free(environ_indexes, head);
	}
	else
	{
		if (value == NULL)
			value = "";
		if (gc_setenv(name, value, head))
			return (1);
	}
	return (0);
}
