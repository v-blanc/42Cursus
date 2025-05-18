/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:33:58 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/18 14:27:00 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "exec.h"

int	pwd(int fd)
{
	char	path[PATH_MAX];

	if (getcwd(path, PATH_MAX) == NULL)
	{
		print(2, "minishell: getcwd: %s\n", strerror(errno));
		return (1);
	}
	else
		print(fd, "%s\n", path);
	return (0);
}
