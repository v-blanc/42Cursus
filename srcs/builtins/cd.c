#include "../../include/minishell.h"

static char	*path_handler(char *path)
{
	char	*new_path;

	new_path = NULL;
	if (path == NULL || ft_strlen(path) == 0)
	{
		new_path = getenv("HOME");
		if (new_path == NULL)
		{
			printf("cd: HOME not set\n");
			return (NULL);
		}
	}
	else if (!ft_strncmp(path, "-", 2))
	{
		new_path = getenv("OLDPWD");
		if (new_path == NULL)
		{
			printf("cd: OLDPWD not set\n");
			return (NULL);
		}
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
		return (0);
	}
	if (getcwd(new_path, PATH_MAX) == NULL)
	{
		printf("getcwd: %s\n", strerror(errno));
		return (0);
	}
	pwd_path = getenv("PWD");
	if (!pwd_path)
		return (0);
	if (gc_setenv("OLDPWD", pwd_path, head) || gc_setenv("PWD", new_path, head))
		return (1);
	return (0);
}

int	cd(int args_count, char **args, t_gc **head)
{
	char	*new_path;
	char	*path;

	if (args_count > 2)
	{
		printf("cd: too many arguments\n");
		return (0);
	}
	path = args[0];
	new_path = gc_malloc(PATH_MAX, head);
	if (!new_path)
		return (1);
	path = path_handler(path);
	if (path == NULL)
		return (0);
	if (cd_exec(path, new_path, head))
		return (1);
	return (0);
}
