/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:49:58 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/20 18:28:38 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	execute_ast(t_ast *node, t_context *ctx)
{
	int	status;

	status = 0;
	if (!node)
		return (0);
	if (node->type == NODE_PAREN)
	{
		if (handle_redirections(node, ctx))
			return (-1);
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
	if (ctx->last_node_type == NODE_REDIR)
		refresh(ctx->backup_fds);
	if (type == AND && status == 0)
		return (execute_ast(node->u_data.s_op.right, ctx));
	else if (type == OR && status != 0)
		return (execute_ast(node->u_data.s_op.right, ctx));
	return (status);
}

int	builtins_manager(t_ast *ast, t_context **context)
{
	int		args_count;
	char	**args;

	args_count = ast->u_data.s_cmd.args_count;
	args = ast->u_data.s_cmd.args;
	if (!ft_strncmp(args[0], "cd", 3))
		return (cd(1, args_count, args + 1, (*context)->head));
	if (!ft_strncmp(args[0], "echo", 5))
		return (echo(1, args + 1));
	if (!ft_strncmp(args[0], "env", 4))
		return (env(ast, context));
	if (!ft_strncmp(args[0], "exit", 5))
		return (exit_(args_count, args + 1, context));
	if (!ft_strncmp(args[0], "export", 8))
		return (export(1, args_count, args + 1, (*context)->head));
	if (!ft_strncmp(args[0], "pwd", 4))
		return (pwd(1));
	if (!ft_strncmp(args[0], "unset", 6))
		return (unset(args + 1, (*context)->head));
	if (!ft_strncmp(args[0], "repeat", 6))
		return (repeat(ast, context));
	return (EXIT_FAILURE);
}

bool	is_builtin(char *command)
{
	if (!command)
		return (false);
	if (!ft_strncmp(command, "cd", 3))
		return (true);
	if (!ft_strncmp(command, "echo", 5))
		return (true);
	if (!ft_strncmp(command, "env", 4))
		return (true);
	if (!ft_strncmp(command, "exit", 5))
		return (true);
	if (!ft_strncmp(command, "export", 8))
		return (true);
	if (!ft_strncmp(command, "pwd", 4))
		return (true);
	if (!ft_strncmp(command, "unset", 6))
		return (true);
	if (!ft_strncmp(command, "repeat", 6))
		return (true);
	return (false);
}
