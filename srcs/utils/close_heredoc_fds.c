/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_heredoc_fds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:44:18 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/20 20:44:18 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		close_heredoc_fds(t_ast *ast);
static void	close_cmd_or_paren(t_ast *n);
static void	close_pipe(t_ast *ast);
static void	close_op(t_ast *ast);
static void	close_redirs(t_ast **redirs, int count);

void	close_heredoc_fds(t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->type == NODE_CMD || ast->type == NODE_PAREN)
		close_cmd_or_paren(ast);
	else if (ast->type == NODE_PIPE)
		close_pipe(ast);
	else if (ast->type == NODE_CMD)
		close_pipe(ast);
	else if (ast->type == NODE_BINARY_OP)
		close_op(ast);
}

static void	close_cmd_or_paren(t_ast *n)
{
	if (n->type == NODE_CMD)
		close_redirs(n->u_data.s_cmd.redirs, n->u_data.s_cmd.redir_count);
	else if (n->type == NODE_PAREN)
		close_redirs(n->u_data.s_par.redirs, n->u_data.s_par.redir_count);
}

static void	close_pipe(t_ast *ast)
{
	const int	cmd_count = ast->u_data.s_pipe.cmd_count;
	int			i;

	i = -1;
	while (++i < cmd_count)
		close_heredoc_fds(ast->u_data.s_pipe.commands[i]);
}

static void	close_op(t_ast *ast)
{
	close_heredoc_fds(ast->u_data.s_op.left);
	close_heredoc_fds(ast->u_data.s_op.right);
}

static void	close_redirs(t_ast **redirs, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (redirs[i]->u_data.s_red.op == REDIR_HEREDOC)
			close(redirs[i]->u_data.s_red.heredoc_fd);
	}
}
