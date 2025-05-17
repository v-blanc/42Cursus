/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_eof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:21:39 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/16 21:12:03 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_eof(t_context **context)
{
	int	exit_status;

	print(1, "exit\n");
	exit_status = (*context)->last_exit_status;
	close((*context)->backup_fds[STDIN_FILENO]);
	close((*context)->backup_fds[STDOUT_FILENO]);
	gc_free_all_perm(*((*context)->head));
	rl_clear_history();
	exit(exit_status);
	return (0);
}
