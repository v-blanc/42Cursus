/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paren.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:58:08 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/15 21:15:35 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_paren_node(t_ast *node, t_ast **par_node, int redir_count,
		t_gc **head)
{
	int	i;

	(*par_node) = gc_malloc(sizeof(t_ast), head);
	if (!par_node)
		return (1);
	(*par_node)->type = NODE_PAREN;
	(*par_node)->u_data.s_par.content = node;
	(*par_node)->u_data.s_par.redir_count = redir_count;
	(*par_node)->u_data.s_par.redirs = (t_ast **)gc_malloc_array(redir_count
			* sizeof(t_ast *), head);
	if (!(*par_node)->u_data.s_par.redirs)
		return (1);
	i = 0;
	while (i < redir_count)
	{
		(*par_node)->u_data.s_par.redirs[i] = (t_ast *)gc_malloc(sizeof(t_ast),
				head);
		if (!(*par_node)->u_data.s_par.redirs[i])
			return (1);
		i++;
	}
	return (0);
}

static t_ast	*handle_redir(t_token **tok, t_ast *node, t_context **ctx)
{
	t_ast	*paren_node;
	int		i;
	t_ast	**curr_redir;

	if (init_paren_node(node, &paren_node, count_cmd_redir(*tok, ctx),
			(*ctx)->head))
		return (NULL);
	i = -1;
	while (++i < paren_node->u_data.s_par.redir_count)
	{
		curr_redir = &paren_node->u_data.s_par.redirs[i];
		(*curr_redir)->type = NODE_REDIR;
		(*curr_redir)->u_data.s_red.op = (*tok)->type;
		(*curr_redir)->u_data.s_red.fd_source = get_fd_source((*tok)->type);
		*tok = (*tok)->next;
		if (!(*tok) || (*tok)->type != WORD)
		{
			print(2, "minishell: syntax error\n");
			(*ctx)->last_exit_status = 2;
			return (NULL);
		}
		(*curr_redir)->u_data.s_red.target = (*tok)->value;
		*tok = (*tok)->next;
	}
	return (paren_node);
}

static int	handle_error(t_token *tokens, t_context **ctx)
{
	if (tokens && (tokens->type != AND && tokens->type != OR) && tokens->next
		&& tokens->next->type == PAREN_OPEN)
	{
		print(2, "minishell: syntax error\n");
		(*ctx)->last_exit_status = 2;
		return (1);
	}
	return (0);
}

static int	handle_syntax_error_paren(t_token *tokens, t_context **ctx)
{
	if (tokens->next && tokens->next->type == PAREN_CLOSE)
	{
		print(2, "minishell: syntaxe error\n");
		(*ctx)->last_exit_status = 2;
		return (1);
	}
	return (0);
}

t_ast	*parse_primary(t_token **tokens, t_context **ctx)
{
	t_ast	*node;

	if (handle_error(*tokens, ctx))
		return (NULL);
	if (*tokens && (*tokens)->type == PAREN_OPEN)
	{
		if (handle_syntax_error_paren(*tokens, ctx))
			return (NULL);
		*tokens = (*tokens)->next;
		node = parser(tokens, ctx);
		if (!node)
			return (NULL);
		if (!*tokens || (*tokens)->type != PAREN_CLOSE)
			return (NULL);
		*tokens = (*tokens)->next;
		if (*tokens && is_redirection((*tokens)->type))
		{
			node = handle_redir(tokens, node, ctx);
			if (!node)
				return (NULL);
		}
		return (node);
	}
	return (parse_command(tokens, ctx));
}
