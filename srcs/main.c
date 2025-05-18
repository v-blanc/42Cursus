/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:46:57 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/18 12:39:37 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: move to another file
void	refresh(int backup_fds[2])
{
	dup2(backup_fds[STDIN_FILENO], STDIN_FILENO);
	dup2(backup_fds[STDOUT_FILENO], STDOUT_FILENO);
	close(backup_fds[STDIN_FILENO]);
	close(backup_fds[STDOUT_FILENO]);
	backup_fds[STDIN_FILENO] = dup(STDIN_FILENO);
	backup_fds[STDOUT_FILENO] = dup(STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_gc		*head;
	t_context	*context;

	head = NULL;
	context = NULL;
	if (init_context(&context, argc, argv, &head))
		return (1);
	if (update_shlvl(&head))
		return (1);
	init_sig();
	if (init_environ(&head))
		return (1);
	set_input(&context);
	return (0);
}
