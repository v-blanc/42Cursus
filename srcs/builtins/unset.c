#include "../../include/minishell.h"

extern char	**environ;

static int	to_unset_found(char **to_unset)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (to_unset[i])
	{
		j = 0;
		while (environ[j])
		{
			if (!ft_strncmp(environ[j], to_unset[i], ft_strlen(to_unset[i])))
				found++;
			j++;
		}
		i++;
	}
	return (found);
}

static int	unset_env(char ***new_env, char *name, t_garbage_collector **head)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], name, ft_strlen(name)))
			i++;
		if (!environ[i])
			return (0);
		(*new_env)[j] = gc_malloc(ft_strlen(environ[i]) + 1, head);
		if (!(*new_env)[j])
			return (1);
		ft_strlcpy((*new_env)[j], environ[i], ft_strlen(environ[i]) + 1);
		i++;
		j++;
	}
	return (1);
}

int	unset(char **to_unset, t_garbage_collector **head)
{
	char	**new_env;
	int		new_env_size;
	int		i;

	if (to_unset == NULL || to_unset[0] == NULL)
	{
		printf("unset: not enough arguments\n");
		return (1);
	}
	new_env_size = ft_strlen_array(environ) - to_unset_found(to_unset);
	new_env = (char **)gc_malloc_array(new_env_size, head);
	if (!new_env)
		return (1);
	i = 0;
	while (to_unset[i])
	{
		if (unset_env(&new_env, to_unset[i], head))
			return (1);
		i++;
	}
	environ = new_env;
	return (0);
}
