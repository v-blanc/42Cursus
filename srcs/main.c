/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:46:57 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/18 15:56:17 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_input.h"

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

static void	exit_main(t_context *ctx)
{
	close(ctx->backup_fds[STDIN_FILENO]);
	close(ctx->backup_fds[STDOUT_FILENO]);
	gc_free_all_perm(*(ctx->head));
	exit(1);
}

int	main(int argc, char **argv)
{
	t_gc		*head;
	t_context	*context;

	head = NULL;
	context = NULL;
	init_sig();
	if (init_context(&context, argc, argv, &head))
		exit_main(context);
	if (init_environ(&head))
		exit_main(context);
	if (update_shlvl(&head))
		exit_main(context);
	set_input(&context);
	return (0);
}
