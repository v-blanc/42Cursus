/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:09:10 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/21 17:10:30 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			handle_pipes(t_ast *pipe_node, t_context *ctx);
static bool	c_pipes(int (**pipes)[2], t_context *ctx, int cmds_nb);
static void	execute_child(int i, int (*pipes)[2], t_ast *pn, t_context *ctx);
static void	wait_children(pid_t *pids, int cmds_nb, t_context *ctx);

int	handle_pipes(t_ast *pipe_node, t_context *ctx)
{
	pid_t		*pids;
	const int	cmds_nb = pipe_node->u_data.s_pipe.cmd_count;
	int			i;
	t_ast		*curr_cmd;
	int			(*pipes)[2];

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
		curr_cmd = pipe_node->u_data.s_pipe.commands[i];
		wait_for_heredocs(curr_cmd, pids);
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
	{
		if (pipe((*pipes)[i]) < 0)
		{
			close_pipes(*pipes, i);
			return (false);
		}
	}
	return (true);
}

static void	execute_child(int i, int (*pipes)[2], t_ast *pn, t_context *ctx)
{
	int	status;

	status = 0;
	if (i > 0)
	{
		if (dup2(pipes[i - 1][STDIN_FILENO], STDIN_FILENO) < 0)
		{
			close_pipes(pipes, pn->u_data.s_pipe.cmd_count - 1);
			exit_eof(&ctx);
		}
	}
	if (i < pn->u_data.s_pipe.cmd_count - 1)
	{
		if (dup2(pipes[i][STDOUT_FILENO], STDOUT_FILENO) < 0)
		{
			close_pipes(pipes, pn->u_data.s_pipe.cmd_count - 1);
			exit_eof(&ctx);
		}
	}
	clean_exit(pipes, i, pn, ctx);
}

static void	wait_children(pid_t *pids, int cmds_nb, t_context *ctx)
{
	int	i;
	int	status;

	status = 0;
	i = -1;
	while (++i < cmds_nb)
	{
		waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			ctx->last_exit_status = WEXITSTATUS(status);
	}
}
