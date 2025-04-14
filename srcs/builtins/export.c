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

static int	get_environ_sorted_indexes(int **environ_indexes, t_gc **head)
{
	int	i;
	int	len_environ;

	len_environ = ft_strlen_array(environ);
	// TODO: use gc_malloc_perm() and delete old environ
	(*environ_indexes) = (int *)gc_malloc(sizeof(int) * len_environ, head);
	if (!(*environ_indexes))
		return (1);
	i = -1;
	while (environ[++i])
		(*environ_indexes)[i] = i;
	sort_environ_indexes(*environ_indexes);
	return (0);
}

static int	print_export(t_gc **head)
{
	int	*env_ind;
	int	i;

	env_ind = NULL;
	if (get_environ_sorted_indexes(&env_ind, head))
		return (1);
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[env_ind[i]], "_=", 2) != 0)
			printf("%s\n", environ[env_ind[i]]);
		i++;
	}
	gc_free(env_ind, head);
	return (0);
}

static int	export_one_var(char *arg, t_gc **head)
{
	char	*name;
	char	*value;
	int		i;

	name = NULL;
	value = "";
	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	name = gc_strndup(arg, i, head);
	if (arg[i] && arg[i + 1])
		value = gc_strdup(&arg[i + 1], head);
	printf(">> name: `%s` value: `%s`\n", name, value);
	if (gc_setenv(name, value, head))
		return (1);
	return (0);
}

int	export(int args_count, char **args, t_gc **head)
{
	int	i;

	if (args_count == 1)
	{
		if (print_export(head))
			return (1);
	}
	else
	{
		i = 0;
		while (args[i])
		{
			if (export_one_var(args[i], head))
				return (1);
			i++;
		}
	}
	return (0);
}
