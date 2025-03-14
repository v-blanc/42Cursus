#include "../../include/minishell.h"

extern char	**environ;

int	cd(char *path)
{
	extern char	**environ;

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
	ft_setenv("PWD", getcwd(NULL, 0));
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	printf(">> %s\n", getenv("OLDPWD"));
// 	pwd();
// 	cd("../../include");
// 	pwd();
// 	if (argc == 2)
// 		cd(argv[1]);
// 	else if (argc == 1)
// 		cd(NULL);
// 	else
// 		printf("cd: too many arguments\n");
// 	pwd();
// 	return (0);
// }
