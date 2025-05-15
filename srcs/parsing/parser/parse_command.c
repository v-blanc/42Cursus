/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:28 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/15 17:48:40 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_cmd_node(t_ast **ast, int args_count, int redir_count,
		t_gc **head)
{
	int	i;

	(*ast)->type = NODE_CMD;
	(*ast)->u_data.s_cmd.args_count = args_count;
	(*ast)->u_data.s_cmd.args = (char **)gc_malloc_array(sizeof(char *)
			* args_count, head);
	if (!(*ast)->u_data.s_cmd.args)
		return (1);
	(*ast)->u_data.s_cmd.redir_count = redir_count;
	(*ast)->u_data.s_cmd.redirs = (t_ast **)gc_malloc_array(sizeof(t_ast *)
			* redir_count, head);
	if (!(*ast)->u_data.s_cmd.redirs)
		return (1);
	i = 0;
	while (i < redir_count)
	{
		(*ast)->u_data.s_cmd.redirs[i] = (t_ast *)gc_malloc(sizeof(t_ast),
				head);
		if (!(*ast)->u_data.s_cmd.redirs[i])
			return (1);
		i++;
	}
	return (0);
}

static int	init_parse_command(t_token **tok, t_ast **ast, t_context **ctx)
{
	int	args_count;
	int	redir_count;

	*ast = gc_malloc(sizeof(t_ast), (*ctx)->head);
	if (!(*ast))
		return (1);
	args_count = count_cmd_args(*tok);
	redir_count = count_cmd_redir(*tok, ctx);
	if (args_count == -1 || redir_count == -1)
		return (1);
	if (init_cmd_node(ast, args_count, redir_count, (*ctx)->head))
		return (1);
	return (0);
}

int	get_fd_source(t_token_type type)
{
	if (type == REDIR_OUT || type == REDIR_APPEND)
		return (1);
	return (0);
}

static int	sub_parse_command(t_token **tok, t_ast **ast, int *j,
		t_context **ctx)
{
	int	fd_source;

	(*ast)->u_data.s_cmd.redirs[*j]->type = NODE_REDIR;
	(*ast)->u_data.s_cmd.redirs[*j]->u_data.s_red.op = (*tok)->type;
	fd_source = get_fd_source((*tok)->type);
	(*ast)->u_data.s_cmd.redirs[*j]->u_data.s_red.fd_source = fd_source;
	*tok = (*tok)->next;
	if (!(*tok) || (*tok)->type != WORD)
	{
		print(2, "syntax error\n");
		(*ctx)->last_exit_status = 2;
		return (1);
	}
	(*ast)->u_data.s_cmd.redirs[*j]->u_data.s_red.to_expand = ((*tok)->quote == NO_QUOTE);
	(*ast)->u_data.s_cmd.redirs[(*j)++]->u_data.s_red.target = (*tok)->value;
	*tok = (*tok)->next;
	return (0);
}

t_ast	*parse_command(t_token **tok, t_context **ctx)
{
	t_ast	*ast;
	int		i;
	int		j;

	if (init_parse_command(tok, &ast, ctx))
		return (NULL);
	if (!(*tok))
		return (ast);
	i = 0;
	j = 0;
	while (*tok && ((*tok)->type == WORD || is_redirection((*tok)->type)))
	{
		if ((*tok)->type == WORD)
		{
			ast->u_data.s_cmd.args[i++] = (*tok)->value;
			*tok = (*tok)->next;
		}
		else if (is_redirection((*tok)->type))
		{
			if (sub_parse_command(tok, &ast, &j, ctx))
				return (NULL);
		}
	}
	return (ast);
}
