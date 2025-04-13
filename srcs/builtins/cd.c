#include "../../include/minishell.h"

static char	*path_handler(char *path)
{
	char	*new_path;

	new_path = NULL;
	if (path == NULL)
	{
		new_path = getenv("HOME");
		if (new_path == NULL)
			return (NULL);
	}
	else if (!ft_strcmp(path, "-"))
	{
		new_path = getenv("OLDPWD");
		if (new_path == NULL)
			return (NULL);
		printf("%s\n", new_path);
	}
	else
		new_path = path;
	return (new_path);
}

static int	cd_exec(char *path, char *new_path, t_gc **head)
{
	char	*pwd_path;

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
	pwd_path = getenv("PWD");
	if (!pwd_path)
		return (1);
	if (gc_setenv("OLDPWD", pwd_path, head) || gc_setenv("PWD", new_path, head))
		return (1);
	return (0);
}

// TODO: rework cd to use export and/or unset (and then use gc_malloc_perm())
int	cd(char *path, t_gc **head)
{
	char	new_path[PATH_MAX];
	char	*path_home;

	path = path_handler(path);
	if (path == NULL)
		return (1);
	if (path[0] == '~')
	{
		path_home = getenv("HOME");
		if (path_home == NULL)
			return (1);
		ft_strlcpy(new_path, path_home, PATH_MAX);
		ft_strlcat(new_path, path + 1, PATH_MAX);
		path = new_path;
	}
	if (cd_exec(path, new_path, head))
		return (1);
	return (0);
}
