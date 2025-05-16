/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:30:04 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/16 16:18:06 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			execute_ast(t_ast *node, t_context *ctx);
int			handle_operators(t_ast *node, t_context *ctx);
static char	*track_paths(char *command, t_gc **head);

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
		if (ctx->last_node_type == 666)
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
			print(2, "minishell: %s: command not found\n",
				c->u_data.s_cmd.args[0]);
		return (126);
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

static char	*track_paths(char *command, t_gc **head)
{
	const char	*path = getenv("PATH");
	char		**directories;
	char		*whole_path;
	short		i;
	struct stat	sh;

	if (!command)
		return (NULL);
	if (ft_strchr(command, '/') || !path)
	{
		if (!stat(command, &sh))
		{
			if (S_ISDIR(sh.st_mode))
			{
				print(2, "minishell: %s: Is a directory\n", command);
				return (NULL);
			}
			else if (access(command, X_OK))
			{
				print(2, "minishell: %s: Permission denied\n", command);
				return (NULL);
			}
			else if (!(sh.st_mode & S_IXUSR))
			{
				print(2, "minishell: %s: No such file or directory\n", command);
				return (NULL);
			}
		}
		return (gc_strdup(command, head));
	}
	if (stat(path, &sh) == 0)
	{
		if (S_ISDIR(sh.st_mode))
			print(2, "minishell: %s: Is a directory\n", command);
		if (access(path, X_OK) != 0)
			print(2, "minishell: %s: Permission denied\n", command);
		return (NULL);
	}
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
