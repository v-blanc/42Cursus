/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:30:04 by yabokhar          #+#    #+#             */
/*   Updated: 2025/04/17 19:52:21 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			execute_ast(t_ast *node, t_context *ctx);
static int	execute_command(t_ast *command, t_context *ctx);
static int	handle_redirections(t_ast *c, t_gc **head);
static char	*track_paths(char *command, t_gc **head);

extern char	**environ;

int	handle_operators(t_ast *node, t_context *ctx)
{
	int	status;
	int	type;

	type = node->u_data.s_op.op;
	status = execute_ast(node->u_data.s_op.left, ctx);
	if (type == AND && status == 0)
		return (execute_ast(node->u_data.s_op.right, ctx));
	else if (type == OR && status == 1)
		return (execute_ast(node->u_data.s_op.right, ctx));
	return (type == AND);
}

int	execute_ast(t_ast *node, t_context *ctx)
{
	int	status;

	status = 0;
	if (!node)
		return (0);
	if (node->type == NODE_PIPE)
		status = handle_pipes(node, ctx);
	else if (node->type == NODE_REDIR)
		status = handle_redirections(node, ctx->head);
	else if (node->type == NODE_CMD)
		status = execute_command(node, ctx);
	else if (node->type == NODE_BINARY_OP)
		status = handle_operators(node, ctx);
	// print(2, "status: %d\n", status);
	ctx->last_exit_status = status;
	return (status);
}

void	close_pipes(int (*pipes)[2], int pipes_nb)
{
	int	i;

	i = -1;
	while (++i < pipes_nb)
	{
		close(pipes[i][IN_FD]);
		close(pipes[i][OUT_FD]);
	}
}

int	handle_pipes(t_ast *pipe_node, t_context *ctx)
{
	const int	cmds_nb = pipe_node->u_data.s_pipe.cmd_count;
	pid_t		*pids;
	int			i;
	int			status;

	int(*pipes)[2];
	pipes = gc_malloc(sizeof(int[2]) * (cmds_nb - 1), ctx->head);
	pids = gc_malloc(sizeof(pid_t) * cmds_nb, ctx->head);
	i = -1;
	while (++i < cmds_nb - 1)
		pipe(pipes[i]);
	i = -1;
	while (++i < cmds_nb)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			status = 0;
			if (i > 0)
				dup2(pipes[i - 1][IN_FD], STDIN_FILENO);
			if (i < cmds_nb - 1)
				dup2(pipes[i][OUT_FD], STDOUT_FILENO);
			close_pipes(pipes, cmds_nb - 1);
			status = execute_command(pipe_node->u_data.s_pipe.commands[i], ctx);
			gc_free_all_perm(*(ctx->head));
			exit(status);
		}
	}
	close_pipes(pipes, cmds_nb - 1);
	i = -1;
	while (++i < cmds_nb)
		waitpid(pids[i], &status, 0);
	ctx->last_exit_status = WEXITSTATUS(status);
	return (ctx->last_exit_status);
}

static int	handle_redirections(t_ast *c, t_gc **head)
{
	int		i;
	int		fd;
	t_ast	*redir;

	(void)head;
	i = -1;
	while (++i < c->u_data.s_cmd.redir_count)
	{
		redir = c->u_data.s_cmd.redirs[i];
		if (redir->u_data.s_red.op == REDIR_OUT)
			fd = open(redir->u_data.s_red.target, O_WRONLY | O_CREAT | O_TRUNC,
					0644);
		else if (redir->u_data.s_red.op == REDIR_APPEND)
			fd = open(redir->u_data.s_red.target, O_WRONLY | O_CREAT | O_APPEND,
					0644);
		else if (redir->u_data.s_red.op == REDIR_IN)
			fd = open(redir->u_data.s_red.target, O_RDONLY);
		else if (redir->u_data.s_red.op == REDIR_HEREDOC)
			fd = handle_heredoc(redir->u_data.s_red.target);
		if (redir->u_data.s_red.op == REDIR_OUT
			|| redir->u_data.s_red.op == REDIR_APPEND)
			dup2(fd, STDOUT_FILENO);
		else
			dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (0);
}

static int	execute_command(t_ast *c, t_context *ctx)
{
	char	*path;
	pid_t	pid;
	int		status;

	if (handle_redirections(c, ctx->head))
		return (1);

	path = track_paths(c->u_data.s_cmd.args[0], ctx->head);
	if ((!is_builtin(c->u_data.s_cmd.args[0])) && (!path || access(path, X_OK) != 0))
	{
		print(2, "minishell: %s: command not found\n", c->u_data.s_cmd.args[0]);
		return (127);
	}
	if (ft_strcmp(c->u_data.s_cmd.args[0], "exit") == 0)
		exit_(c->u_data.s_cmd.args_count, c->u_data.s_cmd.args + 1, &ctx);
	pid = fork();
	if (pid == 0)
	{
		if (is_builtin(c->u_data.s_cmd.args[0]))
			builtins_manager(c, &ctx);
		else
			execve(path, c->u_data.s_cmd.args, environ);
	}
	status = 0;
	waitpid(pid, &status, 0);
	ctx->last_exit_status = WEXITSTATUS(status);
	return (ctx->last_exit_status);
}

static char	*track_paths(char *command, t_gc **head)
{
	const char	*path = getenv("PATH");
	char		**directories;
	char		*whole_path;
	short		i;

	if (!command)
		return (NULL);
	if (ft_strchr(command, '/') || !path)
		return (gc_strdup(command, head));
	directories = gc_split(path, ':', head);
	if (!directories)
		return (NULL);
	i = -1;
	while (directories[++i])
	{
		whole_path = gc_strjoin(directories[i], "/", head);
		whole_path = gc_strjoin(whole_path, command, head);
		if (access(whole_path, X_OK) == 0)
			return (whole_path);
	}
	return (NULL);
}
