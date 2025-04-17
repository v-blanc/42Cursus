#include "minishell.h"

extern char	**environ;

static int	to_unset_found(char **to_unset)
{
	int	i;
	int	found;

	found = 0;
	i = 0;
	while (to_unset[i])
	{
		if (getenv(to_unset[i]))
			found++;
		i++;
	}
	return (found);
}

static int	sub_unset_env(char **to_unset, int *k, char **name, t_gc **head)
{
	*name = gc_strjoin(to_unset[(*k)++], "=", head);
	if (!*name)
		return (1);
	return (0);
}
static int	unset_env(char ***new_env, char **to_unset, t_gc **head)
{
	int		i;
	int		j;
	int		k;
	char	*name;

	i = 0;
	j = 0;
	while (environ[i])
	{
		k = 0;
		while (environ[i] && to_unset[k])
		{
			if (sub_unset_env(to_unset, &k, &name, head))
				return (1);
			if (!ft_strncmp(environ[i], name, ft_strlen(name)))
			{
				i++;
				k = 0;
				continue ;
			}
		}
		if (environ[i])
			(*new_env)[j++] = environ[i++];
	}
	return (0);
}

int	unset(char **to_unset, t_gc **head)
{
	char	**new_env;
	int		new_env_size;

	if (to_unset == NULL || to_unset[0] == NULL)
		return (0);
	if (to_unset_found(to_unset) == 0)
		return (0);
	new_env_size = ft_strlen_array(environ) - to_unset_found(to_unset);
	new_env = (char **)gc_malloc_array_perm(new_env_size + 1, head);
	if (!new_env)
		return (1);
	if (unset_env(&new_env, to_unset, head))
		return (1);
	environ = new_env;
	return (0);
}
