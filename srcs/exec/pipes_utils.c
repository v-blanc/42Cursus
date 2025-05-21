/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:55:35 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/21 17:08:43 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	wait_for_heredocs(t_ast *current, pid_t *pids)

{
	int	i;

	i = 0;
	while (current->u_data.s_cmd.redirs && current->u_data.s_cmd.redirs[i])
	{
		if (current->u_data.s_cmd.redirs[i]->u_data.s_red.op == REDIR_HEREDOC)
			waitpid(pids[i], NULL, 0);
		i++;
	}
}

void	clean_exit(int (*pipes)[2], int i, t_ast *pipe_node, t_context *ctx)

{
	int	status;

	status = 0;
	close_pipes(pipes, pipe_node->u_data.s_pipe.cmd_count - 1);
	status = execute_ast(pipe_node->u_data.s_pipe.commands[i], ctx);
	close(ctx->backup_fds[STDIN_FILENO]);
	close(ctx->backup_fds[STDOUT_FILENO]);
	close_heredoc_fds(pipe_node);
	gc_free_all_perm(*(ctx->head));
	exit(status);
}

void	close_pipes(int (*pipes)[2], int cmds_nb)
{
	int	i;

	i = 0;
	while (i < cmds_nb)
	{
		close(pipes[i][STDIN_FILENO]);
		close(pipes[i][STDOUT_FILENO]);
		i++;
	}
}
