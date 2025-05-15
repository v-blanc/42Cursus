/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:35 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/15 21:15:46 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sub_parser(t_token **tokens, t_ast **left, t_context **ctx)
{
	t_ast			*right;
	t_ast			*op_node;
	t_token_type	op_type;

	op_type = (*tokens)->type;
	*tokens = (*tokens)->next;
	if (*tokens && (*tokens)->type != WORD && (*tokens)->type != PAREN_OPEN
		&& (*tokens)->type != PAREN_CLOSE)
	{
		print(2, "minishell: syntax error\n");
		(*ctx)->last_exit_status = 2;
		return (1);
	}
	right = parse_pipeline(tokens, ctx);
	if (!right)
		return (1);
	op_node = gc_malloc(sizeof(t_ast), (*ctx)->head);
	if (!op_node)
		return (1);
	op_node->type = NODE_BINARY_OP;
	op_node->u_data.s_op.left = *left;
	op_node->u_data.s_op.right = right;
	op_node->u_data.s_op.op = op_type;
	*left = op_node;
	return (0);
}

t_ast	*parser(t_token **tokens, t_context **ctx)
{
	t_ast	*left;

	left = parse_pipeline(tokens, ctx);
	if (!left)
		return (NULL);
	while (*tokens && ((*tokens)->type == AND || (*tokens)->type == OR))
	{
		if (sub_parser(tokens, &left, ctx))
			return (NULL);
	}
	return (left);
}
