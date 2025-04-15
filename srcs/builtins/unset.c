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

static int	unset_env(char ***new_env, char *name, t_gc **head)
{
	int	i;
	int	j;
	int	len_name;

	i = 0;
	j = 0;
	name = gc_strjoin(name, "=", head);
	if (!name)
		return (1);
	len_name = ft_strlen(name);
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], name, len_name))
			i++;
		else
		{
			(*new_env)[j] = environ[i];
			i++;
			j++;
		}
	}
	return (0);
}

int	unset(char **to_unset, t_gc **head)
{
	char	**new_env;
	int		new_env_size;
	int		i;

	if (to_unset == NULL || to_unset[0] == NULL)
		return (0);
	if (to_unset_found(to_unset) == 0)
		return (0);
	new_env_size = ft_strlen_array(environ) - to_unset_found(to_unset);
	new_env = (char **)gc_malloc_array_perm(new_env_size, head);
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
