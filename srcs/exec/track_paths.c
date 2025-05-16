/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:52:24 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/16 17:45:31 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*track_paths(char *command, t_gc **head);
static char	*relative_path(char *command, t_gc **head);
static bool	cannot_access_file(const char *path);

char	*track_paths(char *command, t_gc **head)

{
	const char	*path = getenv("PATH");
	char		**directories;
	char		*whole_path;
	short		i;

	if (!command)
		return (NULL);
	if (ft_strchr(command, '/') || !path)
		return (relative_path(command, head));
	if (cannot_access_file(path))
		return (NULL);
	directories = gc_split(path, ':', head);
	if (!directories)
		return (NULL);
	i = -1;
	while (directories[++i])
	{
		whole_path = gc_strjoin(directories[i], "/", head);
		whole_path = gc_strjoin(whole_path, command, head);
		if (access(whole_path, X_OK) == 0)
			return (whole_path);
	}
	return (NULL);
}

static char	*relative_path(char *command, t_gc **head)

{
	struct stat	sh;

	if (!stat(command, &sh))
	{
		if (S_ISDIR(sh.st_mode))
			print(2, "minishell: %s: Is a directory\n", command);
		else if (access(command, X_OK))
			print(2, "minishell: %s: Permission denied\n", command);
		else if (!(sh.st_mode & S_IXUSR))
			print(2, "minishell: %s: No such file or directory\n", command);
		return (NULL);
	}
	return (gc_strdup(command, head));
}

static bool	cannot_access_file(const char *path)

{
	struct stat	sh;

	if (!stat(path, &sh))
	{
		if (S_ISDIR(sh.st_mode))
			print(2, "minishell: %s: Is a directory\n", path);
		if (access(path, X_OK) != 0)
			print(2, "minishell: %s: Permission denied\n", path);
		return (true);
	}
	return (false);
}
