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

// TODO: handle errors (errno) ?
int	cd(char *path)
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
	if (chdir(path) == -1)
	{
		if (access(path, F_OK) == -1)
			return (printf("cd: no such file or directory: %s\n", path), 1);
		if (access(path, X_OK) == -1)
			return (printf("cd: permission denied: %s\n", path), 1);
		printf("cd: not a directory: %s\n", path);
		return (1);
	}
	ft_setenv("OLDPWD", getenv("PWD"));
	if (getcwd(new_path, PATH_MAX) == NULL)
		return (printf("getcwd error\n"), 1);
	ft_setenv("PWD", new_path);
	return (0);
}
