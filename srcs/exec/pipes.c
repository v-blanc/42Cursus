/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:09:10 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/15 21:47:26 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			handle_pipes(t_ast *pipe_node, t_context *ctx);
static bool	c_pipes(int (**pipes)[2], t_context *ctx, int cmds_nb);
static void	execute_child(int i, int (*pipes)[2], t_ast *pn, t_context *ctx);
static void	wait_children(pid_t *pids, int cmds_nb, t_context *ctx);
static void	close_pipes(int (*pipes)[2], int cmds_nb);

int	handle_pipes(t_ast *pipe_node, t_context *ctx)

{
	int			(*pipes)[2];
	pid_t		*pids;
	const int	cmds_nb = pipe_node->u_data.s_pipe.cmd_count;
	int			i;

	pids = gc_malloc(sizeof(pid_t) * cmds_nb, ctx->head);
	if (!c_pipes(&pipes, ctx, cmds_nb))
		return (EXIT_FAILURE);
	i = -1;
	while (++i < cmds_nb)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			execute_child(i, pipes, pipe_node, ctx);
		else if (pids[i] < 0)
			return (EXIT_FAILURE);
	}
	close_pipes(pipes, cmds_nb - 1);
	wait_children(pids, cmds_nb, ctx);
	return (ctx->last_exit_status);
}

static bool	c_pipes(int (**pipes)[2], t_context *ctx, int cmds_nb)

{
	int	i;

	*pipes = gc_malloc(sizeof(int [2]) * (cmds_nb - 1), ctx->head);
	if (!*pipes)
		return (false);
	i = -1;
	while (++i < cmds_nb - 1)
		if (pipe((*pipes)[i]) < 0)
			return (false);
	return (true);
}

static void	execute_child(int i, int (*pipes)[2], t_ast *pn, t_context *ctx)

{
	int	status;

	status = 0;
	if (i > 0)
		dup2(pipes[i - 1][IN_FD], STDIN_FILENO);
	if (i < pn->u_data.s_pipe.cmd_count - 1)
		dup2(pipes[i][OUT_FD], STDOUT_FILENO);
	close_pipes(pipes, pn->u_data.s_pipe.cmd_count - 1);
	status = execute_ast(pn->u_data.s_pipe.commands[i], ctx);
	close(ctx->backup_fds[0]);
	close(ctx->backup_fds[1]);
	gc_free_all_perm(*(ctx->head));
	exit(status);
}

static void	wait_children(pid_t *pids, int cmds_nb, t_context *ctx)

{
	int	i;
	int	status;

	i = -1;
	while (++i < cmds_nb)
	{
		waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			ctx->last_exit_status = WEXITSTATUS(status);
	}
}

static void	close_pipes(int (*pipes)[2], int cmds_nb)

{
	int	i;
	
	i = 0;
	while (i < cmds_nb)
	{
		close(pipes[i][IN_FD]);
		close(pipes[i][OUT_FD]);
		i++;
	}
}
