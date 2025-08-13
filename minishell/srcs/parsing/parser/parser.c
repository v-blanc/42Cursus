/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:35 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 13:41:33 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	sub_parser(t_token **tokens, t_ast **left, t_context **ctx)
{
	t_ast			*right;
	t_ast			*op_node;
	t_token_type	op_type;

	op_type = (*tokens)->type;
	*tokens = (*tokens)->next;
	if (!*tokens)
		return (1);
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
