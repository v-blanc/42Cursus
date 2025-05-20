/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:15:39 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/20 18:28:03 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			handle_redirections(t_ast *c, t_context *ctx);
static int	get_redirections_type(t_ast *c, t_ast ***redir);
static int	get_target(t_ast **redirs, int i);
static void	which_error(char *file);
static int	close_then_return_exit_failure(int fd);

int	handle_redirections(t_ast *c, t_context *ctx)
{
	t_ast	**redirs;
	int		redirs_count;
	int		i;
	int		fd;

	redirs = NULL;
	redirs_count = get_redirections_type(c, &redirs);
	i = -1;
	while (++i < redirs_count)
	{
		fd = get_target(redirs, i);
		if (fd < 0)
		{
			print(2, "minishell: %s: %s\n", redirs[i]->u_data.s_red.target,
				strerror(errno));
			return (EXIT_FAILURE);
		}
		if (redirs[i]->u_data.s_red.op == REDIR_OUT
			|| redirs[i]->u_data.s_red.op == REDIR_APPEND)
		{
			if (dup2(fd, STDOUT_FILENO) < 0)
				close_then_return_exit_failure(fd);
		}
		else if (dup2(fd, STDIN_FILENO) < 0)
			close_then_return_exit_failure(fd);
		close(fd);
	}
	ctx->last_node_type = NODE_REDIR;
	return (EXIT_SUCCESS);
}

static int	get_redirections_type(t_ast *c, t_ast ***redir)
{
	if (!c)
		return (0);
	if (c->type == NODE_CMD)
	{
		*redir = c->u_data.s_cmd.redirs;
		return (c->u_data.s_cmd.redir_count);
	}
	else if (c->type == NODE_PAREN)
	{
		*redir = c->u_data.s_par.redirs;
		return (c->u_data.s_par.redir_count);
	}
	return (0);
}

static int	get_target(t_ast **redirs, int i)
{
	int	fd;

	fd = 0;
	if (redirs[i]->u_data.s_red.op == REDIR_OUT)
		fd = open(redirs[i]->u_data.s_red.target, O_WRONLY | O_CREAT | O_TRUNC,
				0644);
	else if (redirs[i]->u_data.s_red.op == REDIR_APPEND)
		fd = open(redirs[i]->u_data.s_red.target, O_WRONLY | O_CREAT | O_APPEND,
				0644);
	else if (redirs[i]->u_data.s_red.op == REDIR_IN)
		fd = open(redirs[i]->u_data.s_red.target, O_RDONLY);
	else if (redirs[i]->u_data.s_red.op == REDIR_HEREDOC)
		fd = redirs[i]->u_data.s_red.heredoc_fd;
	if (fd < 0)
		which_error(redirs[i]->u_data.s_red.target);
	return (fd);
}

static void	which_error(char *file)
{
	struct stat	sh;

	if (!stat(file, &sh))
	{
		if (!errno)
			return ;
		if (S_ISDIR(sh.st_mode))
			print(2, "minishell: %s: Is a directory\n", file);
		else if (access(file, X_OK))
			print(2, "minishell: %s: Permission denied\n", file);
		else if (!(sh.st_mode & S_IXUSR))
			print(2, "minishell: %s: No such file or directory\n", file);
	}
	return ;
}

static int	close_then_return_exit_failure(int fd)
{
	close(fd);
	return (EXIT_FAILURE);
}
