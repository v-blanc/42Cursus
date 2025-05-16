/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:30:04 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/16 19:05:39 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			execute_ast(t_ast *node, t_context *ctx);
int			handle_operators(t_ast *node, t_context *ctx);

extern char	**environ;

int	execute_ast(t_ast *node, t_context *ctx)
{
	int	status;

	status = 0;
	if (!node)
		return (0);
	if (node->type == NODE_PAREN)
	{
		if (handle_redirections(node, ctx))
			return (-1); // TODO: check if error is correctly handled
		status = execute_ast(node->u_data.s_par.content, ctx);
	}
	else if (node->type == NODE_BINARY_OP)
		status = handle_operators(node, ctx);
	else if (node->type == NODE_PIPE)
		status = handle_pipes(node, ctx);
	else if (node->type == NODE_REDIR)
		status = handle_redirections(node, ctx);
	else if (node->type == NODE_CMD)
		status = execute_command(node, ctx);
	ctx->last_exit_status = status;
	return (status);
}

int	handle_operators(t_ast *node, t_context *ctx)
{
	int	status;
	int	type;

	type = node->u_data.s_op.op;
	status = execute_ast(node->u_data.s_op.left, ctx);
	if (type == AND && status == 0)
		return (execute_ast(node->u_data.s_op.right, ctx));
	else if (type == OR && status != 0)
		return (execute_ast(node->u_data.s_op.right, ctx));
	return (type == AND);
}

int	execute_command(t_ast *c, t_context *ctx)
{
	char	*path;
	pid_t	pid;
	int		status;

	if (c->type == NODE_CMD && !c->u_data.s_cmd.args_count
		&& !c->u_data.s_cmd.redir_count)
		return (0);
	if (handle_redirections(c, ctx))
		return (1);
	if (!c->u_data.s_cmd.args_count)
	{
		refresh(ctx->backup_fds);
		if (ctx->last_node_type == REDIR_HEREDOC)
		{
			ctx->last_node_type = 0;
			return (0);
		}
		c->u_data.s_cmd.args_count++;
		c->u_data.s_cmd.args = get_input(ctx);
		status = execute_command(c, ctx);
		ctx->last_exit_status = WEXITSTATUS(status);
		return (ctx->last_exit_status);
	}
	if (c->u_data.s_cmd.args && c->u_data.s_cmd.args[0]
		&& c->u_data.s_cmd.args[0][0] == '\0')
	{
		print(2, "minishell: '' command not found\n");
		return (127);
	}
	if (is_builtin(c->u_data.s_cmd.args[0]))
		return (builtins_manager(c, &ctx));
	path = track_paths(c->u_data.s_cmd.args[0], ctx->head);
	if ((!is_builtin(c->u_data.s_cmd.args[0])) && (!path || access(path,
				X_OK) != 0))
	{
		if (errno == ENOENT)
		{
			print(2, "minishell: %s: command not found\n", c->u_data.s_cmd.args[0]);
			return (127);
		}
		else
		{
			print(2, "minishell: %s: %s\n", c->u_data.s_cmd.args[0], strerror(errno));
			return (126);
		}
	}
	if (ft_strcmp(c->u_data.s_cmd.args[0], "exit") == 0)
		exit_(c->u_data.s_cmd.args_count, c->u_data.s_cmd.args + 1, &ctx);
	pid = fork();
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(path, c->u_data.s_cmd.args, environ);
		print(2, "minishell: %s: %s\n", c->u_data.s_cmd.args[0],
			strerror(errno));
		close(ctx->backup_fds[0]);
		close(ctx->backup_fds[1]);
		gc_free_all_perm(*ctx->head);
		exit(126);
	}
	status = 0;
	waitpid(pid, &status, 0);
	ctx->last_exit_status = WEXITSTATUS(status);
	return (ctx->last_exit_status);
}
