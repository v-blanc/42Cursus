/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:09:10 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/19 00:27:07 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			handle_pipes(t_ast *pipe_node, t_context *ctx);
static bool	c_pipes(int (**pipes)[2], t_context *ctx, int cmds_nb);
static void	execute_child(int i, int (*pipes)[2], t_ast *pn, t_context *ctx);
static void	wait_children(pid_t *pids, int cmds_nb, t_context *ctx);
static void	close_pipes(int (*pipes)[2], int cmds_nb);

int	handle_pipes(t_ast *pipe_node, t_context *ctx)
{
	pid_t		*pids;
	const int	cmds_nb = pipe_node->u_data.s_pipe.cmd_count;
	int			index[2];
	t_ast		*curr_cmd;

	int(*pipes)[2];
	pids = gc_malloc(sizeof(pid_t) * cmds_nb, ctx->head);
	if (!c_pipes(&pipes, ctx, cmds_nb))
		return (EXIT_FAILURE);
	index[0] = -1;
	while (++index[0] < cmds_nb)
	{
		pids[index[0]] = fork();
		if (pids[index[0]] == 0)
			execute_child(index[0], pipes, pipe_node, ctx);
		else if (pids[index[0]] < 0)
			return (EXIT_FAILURE);
		index[1] = 0;
		curr_cmd = pipe_node->u_data.s_pipe.commands[index[0]];
		while (curr_cmd->u_data.s_cmd.redirs[index[1]])
		{
			if (curr_cmd->u_data.s_cmd.redirs[index[1]]->u_data.s_red.op == 5)
				waitpid(pids[index[0]], NULL, 0);
			index[1]++;
		}
	}
	close_pipes(pipes, cmds_nb - 1);
	wait_children(pids, cmds_nb, ctx);
	return (ctx->last_exit_status);
}

static bool	c_pipes(int (**pipes)[2], t_context *ctx, int cmds_nb)
{
	int	i;

	*pipes = gc_malloc(sizeof(int[2]) * (cmds_nb - 1), ctx->head);
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
		dup2(pipes[i - 1][STDIN_FILENO], STDIN_FILENO);
	if (i < pn->u_data.s_pipe.cmd_count - 1)
		dup2(pipes[i][STDOUT_FILENO], STDOUT_FILENO);
	close_pipes(pipes, pn->u_data.s_pipe.cmd_count - 1);
	status = execute_ast(pn->u_data.s_pipe.commands[i], ctx);
	// if (pn->u_data.s_pipe.commands[i]->u_data.s_cmd.redirs)
	close(ctx->backup_fds[STDIN_FILENO]);
	close(ctx->backup_fds[STDOUT_FILENO]);
	close_heredoc_fds(pn);
	gc_free_all_perm(*(ctx->head));
	exit(status);
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

static void	close_pipes(int (*pipes)[2], int cmds_nb)
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
