#include "../../include/minishell.h"

extern char	**environ;

// TODO: handle errors (errno) ?
int	cd(char *path)
{
	extern char	**environ;
	char		new_path[PATH_MAX];

	printf("cd %s\n", path == NULL ? "" : path); // DEGUB
	if (path == NULL || !ft_strcmp(path, "~"))
		path = getenv("HOME");
	else if (!ft_strcmp(path, "-"))
		path = getenv("OLDPWD");
	if (chdir(path) == -1)
	{
		if (access(path, F_OK) == -1)
		{
			printf("cd: no such file or directory: %s\n", path);
			return (1);
		}
		printf("cd: not a directory: %s\n", path);
		return (1);
	}
	ft_setenv("OLDPWD", getenv("PWD"));
	if (getcwd(new_path, PATH_MAX) == NULL)
		return (1);
	ft_setenv("PWD", new_path);
	return (0);
}
