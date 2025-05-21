/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:46:57 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/21 16:45:24 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_input.h"

static void	exit_main(t_context *ctx)
{
	close(ctx->backup_fds[STDIN_FILENO]);
	close(ctx->backup_fds[STDOUT_FILENO]);
	gc_free_all_perm(*(ctx->head));
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_gc		*head;
	t_context	*context;

	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO)
		|| !isatty(STDERR_FILENO))
		return (EXIT_FAILURE);
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
	return (EXIT_SUCCESS);
}
