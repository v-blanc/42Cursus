/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:33:05 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/10 08:20:26 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*path_handler(int fd, char *path)
{
	char	*new_path;

	new_path = NULL;
	if (path == NULL || ft_strlen(path) == 0)
	{
		new_path = getenv("HOME");
		if (new_path == NULL)
			return (path);
	}
	else if (!ft_strncmp(path, "-", 2))
	{
		new_path = getenv("OLDPWD");
		if (new_path == NULL)
		{
			print(2, "cd: OLDPWD not set\n");
			return (NULL);
		}
		print(fd, "%s\n", new_path);
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
		print(2, "cd: %s: %s\n", strerror(errno), path);
		return (1);
	}
	if (getcwd(new_path, PATH_MAX) == NULL)
	{
		print(2, "getcwd: %s\n", strerror(errno));
		return (1);
	}
	pwd_path = getenv("PWD");
	if (!pwd_path)
	{
		print(2, "cd: PWD not set\n");
		return (1);
	}
	if (gc_setenv("OLDPWD", pwd_path, head) || gc_setenv("PWD", new_path, head))
		return (1);
	return (0);
}

int	cd(int fd, int args_count, char **args, t_gc **head)
{
	char	*new_path;
	char	*path;

	if (args_count > 2)
	{
		print(2, "cd: too many arguments\n");
		return (1);
	}
	path = args[0];
	new_path = gc_malloc(PATH_MAX, head);
	if (!new_path)
		return (1);
	path = path_handler(fd, path);
	if (getenv("HOME"))
	{
		if (expand_tilde(&path, head))
			return (1);
	}
	if (path == NULL)
		return (0);
	return (cd_exec(path, new_path, head));
}
