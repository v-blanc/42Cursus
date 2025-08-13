/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:22:23 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/20 20:42:18 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	refresh(int backup_fds[2])
{
	if (dup2(backup_fds[STDIN_FILENO], STDIN_FILENO) < 0)
		return ;
	if (dup2(backup_fds[STDOUT_FILENO], STDOUT_FILENO) < 0)
	{
		close(backup_fds[STDIN_FILENO]);
		return ;
	}
	close(backup_fds[STDIN_FILENO]);
	close(backup_fds[STDOUT_FILENO]);
	backup_fds[STDIN_FILENO] = dup(STDIN_FILENO);
	backup_fds[STDOUT_FILENO] = dup(STDOUT_FILENO);
}

void	command_fd_dup(int cmd_backup_fds[2])

{
	cmd_backup_fds[STDIN_FILENO] = dup(STDIN_FILENO);
	if (cmd_backup_fds[STDIN_FILENO] < 0)
		return ;
	cmd_backup_fds[STDOUT_FILENO] = dup(STDOUT_FILENO);
	if (cmd_backup_fds[STDOUT_FILENO] < 0)
	{
		close(cmd_backup_fds[STDIN_FILENO]);
		return ;
	}
}

void	command_refresh(int cmd_backup_fds[2])

{
	if (dup2(cmd_backup_fds[STDIN_FILENO], STDIN_FILENO) < 0)
		return ;
	if (dup2(cmd_backup_fds[STDOUT_FILENO], STDOUT_FILENO) < 0)
	{
		close(cmd_backup_fds[STDIN_FILENO]);
		return ;
	}
	close(cmd_backup_fds[STDIN_FILENO]);
	close(cmd_backup_fds[STDOUT_FILENO]);
}
