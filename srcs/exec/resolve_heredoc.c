#include "exec.h"

bool		resolve_all_heredocs(t_ast *ast, t_context *ctx);
static bool	resolve_cmd_or_paren(t_ast *ast, t_context *ctx);
static bool	resolve_pipe(t_ast *ast, t_context *ctx);
static bool	resolve_op(t_ast *ast, t_context *ctx);
static bool	resolve_redirs(t_ast **redirs, int count, t_context *ctx);

bool	resolve_all_heredocs(t_ast *ast, t_context *ctx)
{
	if (!ast)
		return (true);
	if (ast->type == NODE_CMD || ast->type == NODE_PAREN)
		return (resolve_cmd_or_paren(ast, ctx));
	else if (ast->type == NODE_PIPE)
		return (resolve_pipe(ast, ctx));
	else if (ast->type == NODE_BINARY_OP)
		return (resolve_op(ast, ctx));
	return (true);
}

static bool	resolve_cmd_or_paren(t_ast *ast, t_context *ctx)
{
	t_ast	**cmd;
	t_ast	**paren;
	int		count;

	cmd = ast->u_data.s_cmd.redirs;
	paren = ast->u_data.s_par.redirs;
	if (ast->type == NODE_CMD)
	{
		count = ast->u_data.s_cmd.redir_count;
		return (resolve_redirs(cmd, count, ctx));
	}
	if (ast->type == NODE_PAREN)
	{
		count = ast->u_data.s_par.redir_count;
		return (resolve_redirs(paren, count, ctx));
	}
	return (true);
}

static bool	resolve_pipe(t_ast *ast, t_context *ctx)
{
	const int	cmd_count = ast->u_data.s_pipe.cmd_count;
	int			i;

	i = 0;
	while (i < cmd_count)
	{
		if (!resolve_all_heredocs(ast->u_data.s_pipe.commands[i], ctx))
			return (false);
		i++;
	}
	return (true);
}

static bool	resolve_op(t_ast *ast, t_context *ctx)
{
	if (!resolve_all_heredocs(ast->u_data.s_op.left, ctx))
		return (false);
	if (!resolve_all_heredocs(ast->u_data.s_op.right, ctx))
		return (false);
	return (true);
}

static bool	resolve_redirs(t_ast **redirs, int count, t_context *ctx)
{
	int		i;
	int		fd;
	char	*target;
	bool	to_expand;

	i = -1;
	while (++i < count)
	{
		if (redirs[i]->u_data.s_red.op == REDIR_HEREDOC)
		{
			refresh(ctx->backup_fds);
			target = redirs[i]->u_data.s_red.target;
			to_expand = redirs[i]->u_data.s_red.to_expand;
			fd = handle_heredoc(target, to_expand, ctx);
			if (fd < 0)
			{
				refresh(ctx->backup_fds);
				return (false);
			}
			redirs[i]->u_data.s_red.heredoc_fd = fd;
		}
	}
	return (true);
}
