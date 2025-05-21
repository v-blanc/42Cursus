/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:49:58 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/21 15:06:04 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	execute_ast(t_ast *node, t_context *ctx)
{
	int		status;

	status = 0;
	if (!node)
		return (0);
	if (node->type == NODE_PAREN)
	{
		ctx->in_subshell = true;
		if (handle_redirections(node, ctx))
			return (-1);
		status = execute_ast(node->u_data.s_par.content, ctx);
		ctx->in_subshell = false;
	}
	else if (node->type == NODE_BINARY_OP)
		status = handle_operators(node, ctx);
	else if (node->type == NODE_PIPE)
	{
		ctx->in_subshell = true;
		status = handle_pipes(node, ctx);
		ctx->in_subshell = false;
	}
	else if (node->type == NODE_REDIR)
		status = handle_redirections(node, ctx);
	else if (node->type == NODE_CMD)
		status = execute_command(node, ctx);
	ctx->last_exit_status = status;
	return (status);
}

int	handle_operators(t_ast *node, t_context *ctx)
{
	const int	type = node->u_data.s_op.op;
	int			status;
	int			exit_status;
	pid_t		pid;

	pid = fork();
	if (!pid)
	{
		if (handle_redirections(node, ctx))
			exit(EXIT_FAILURE);
		exit_status = execute_ast(node->u_data.s_op.left, ctx);
		if (type == AND && exit_status == 0)
			exit_status = execute_ast(node->u_data.s_op.right, ctx);
		else if (type == OR && exit_status != 0)
			exit_status = execute_ast(node->u_data.s_op.right, ctx);
		gc_free_all_perm(*ctx->head);
		exit(exit_status);
	}
	else if (pid < 0)
		return (EXIT_FAILURE);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		ctx->last_exit_status = WEXITSTATUS(status);
	return (ctx->last_exit_status);
}

int	builtins_manager(t_ast *ast, t_context **context)
{
	int		args_count;
	char	**args;
	int		status;

	status = 0;
	args_count = ast->u_data.s_cmd.args_count;
	args = ast->u_data.s_cmd.args;
	if (!ft_strncmp(args[0], "cd", 3))
		status = cd(1, args_count, args + 1, (*context)->head);
	if (!ft_strncmp(args[0], "echo", 5))
		status = echo(1, args + 1);
	if (!ft_strncmp(args[0], "env", 4))
		status = env(ast, context);
	if (!ft_strncmp(args[0], "exit", 5))
		status = exit_(args_count, args + 1, context);
	if (!ft_strncmp(args[0], "export", 8))
		status = export(1, args_count, args + 1, (*context)->head);
	if (!ft_strncmp(args[0], "pwd", 4))
		status = pwd(1);
	if (!ft_strncmp(args[0], "unset", 6))
		status = unset(args + 1, (*context)->head);
	if (!ft_strncmp(args[0], "repeat", 6))
		status = repeat(ast, context);
	command_refresh((*context)->cmd_backup_fds);
	return (status);
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
