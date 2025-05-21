/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:30:04 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/21 18:00:38 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			execute_command(t_ast *c, t_context *ctx);
static bool	invalid_node_or_redirs(int *error, t_ast *node, t_context *ctx);
static void	let_child_execute(t_ast *node, t_context *ctx, char *path);
static int	wait_for_child(pid_t pid, t_context *ctx);
static int	print_error_and_return(t_ast *node, t_context *ctx);

extern char	**environ;

int	execute_command(t_ast *c, t_context *ctx)
{
	char	*path;
	int		error;
	pid_t	pid;

	command_fd_dup(ctx->cmd_backup_fds);
	if (invalid_node_or_redirs(&error, c, ctx))
		return (error);
	if (is_builtin(c->u_data.s_cmd.args[0]))
		return (builtins_manager(c, &ctx));
	path = track_paths(c->u_data.s_cmd.args[0], ctx->head);
	if ((!is_builtin(c->u_data.s_cmd.args[0])) && (!path || access(path, X_OK)))
		return (print_error_and_return(c, ctx));
	if (ft_strcmp(c->u_data.s_cmd.args[0], "exit") == 0)
		exit_(c->u_data.s_cmd.args_count, c->u_data.s_cmd.args + 1, &ctx);
	pid = fork();
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (!pid)
		let_child_execute(c, ctx, path);
	command_refresh(ctx->cmd_backup_fds);
	return (wait_for_child(pid, ctx));
}

static bool	invalid_node_or_redirs(int *error, t_ast *node, t_context *ctx)
{
	const bool	command_node = (node->type == NODE_CMD);
	const bool	no_args = (node->u_data.s_cmd.args_count == 0);
	const bool	no_redirs = (node->u_data.s_cmd.redir_count == 0);
	char		*command;
	bool		empty_line;

	*error = -1;
	if (command_node && no_args && no_redirs)
		*error = 0;
	else if (handle_redirections(node, ctx))
		*error = EXIT_FAILURE;
	else if (no_args)
		*error = 0;
	if (no_args)
		return (true);
	command = node->u_data.s_cmd.args[0];
	empty_line = (!command[0]);
	if (command && empty_line)
	{
		print(2, "minishell: '' command not found\n");
		*error = 127;
	}
	if (*error == -1)
		return (false);
	return (true);
}

static void	let_child_execute(t_ast *node, t_context *ctx, char *path)
{
	struct stat	sh;
	const char	*command = node->u_data.s_cmd.args[0];
	const char	*error_message = strerror(errno);

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	execve(path, node->u_data.s_cmd.args, environ);
	if (!stat(path, &sh) && S_ISDIR(sh.st_mode))
		print(2, "minishell: %s Is a directory\n", path);
	else
		print(2, "minishell: %s: %s\n", command, error_message);
	close(ctx->backup_fds[STDIN_FILENO]);
	close(ctx->backup_fds[STDOUT_FILENO]);
	close(ctx->cmd_backup_fds[STDIN_FILENO]);
	close(ctx->cmd_backup_fds[STDOUT_FILENO]);
	gc_free_all_perm(*ctx->head);
	exit(126);
}

static int	wait_for_child(pid_t pid, t_context *ctx)
{
	int	status;

	status = 0;
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		ctx->last_exit_status = 128 + WTERMSIG(status);
	else
		ctx->last_exit_status = WEXITSTATUS(status);
	if (errno == ECHILD)
	{
		print(2, "minishell: %s\n", strerror(ECHILD));
		ctx->last_exit_status = EXIT_FAILURE;
	}
	return (ctx->last_exit_status);
}

static int	print_error_and_return(t_ast *node, t_context *ctx)
{
	const char	*command = node->u_data.s_cmd.args[0];
	const char	*error_message = strerror(errno);

	close(ctx->backup_fds[STDIN_FILENO]);
	close(ctx->backup_fds[STDOUT_FILENO]);
	close(ctx->cmd_backup_fds[STDIN_FILENO]);
	close(ctx->cmd_backup_fds[STDOUT_FILENO]);
	if (errno == ENOENT)
	{
		print(2, "minishell: %s: command not found\n", command);
		return (127);
	}
	else
	{
		print(2, "minishell: %s: %s\n", command, error_message);
		return (126);
	}
}
