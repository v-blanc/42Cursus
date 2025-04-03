#include "../../include/minishell.h"

static char	*path_handler(char *path)
{
	char	*new_path;

	new_path = NULL;
	if (path == NULL)
		ft_strlcpy(new_path, getenv("HOME"), PATH_MAX);
	else if (!ft_strcmp(path, "-"))
	{
		new_path = getenv("OLDPWD");
		printf("%s\n", new_path);
	}
	else
		new_path = path;
	return (new_path);
}

extern char	**environ;

int	cd(char *path, t_garbage_collector **head)
{
	char	new_path[PATH_MAX];

	path = path_handler(path);
	if (path[0] == '~')
	{
		ft_strlcpy(new_path, getenv("HOME"), PATH_MAX);
		ft_strlcat(new_path, path + 1, PATH_MAX);
		path = new_path;
	}
	printf("cd %s\n", path); // TODO: DEGUB: remove when done
	if (chdir(path) < 0)
	{
		printf("cd: %s: %s\n", strerror(errno), path);
		return (1);
	}
	if (getcwd(new_path, PATH_MAX) == NULL)
	{
		printf("getcwd: %s\n", strerror(errno));
		return (1);
	}
	if (gc_setenv("OLDPWD", getenv("PWD"), head) || gc_setenv("PWD", new_path,
			head))
		return (1);
	return (0);
}
