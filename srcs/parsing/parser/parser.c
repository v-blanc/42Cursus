#include "minishell.h"

static int	sub_parser(t_token **tokens, t_ast **left, t_gc **head)
{
	t_ast			*right;
	t_ast			*op_node;
	t_token_type	op_type;

	op_type = (*tokens)->type;
	*tokens = (*tokens)->next;
	if (*tokens && (*tokens)->type != WORD)
	{
		print(2, "syntax error\n");
		return (1);
	}
	right = parse_pipeline(tokens, head);
	if (!right)
		return (1);
	op_node = gc_malloc(sizeof(t_ast), head);
	if (!op_node)
		return (1);
	op_node->type = NODE_BINARY_OP;
	op_node->u_data.s_op.left = *left;
	op_node->u_data.s_op.right = right;
	op_node->u_data.s_op.op = op_type;
	*left = op_node;
	return (0);
}

t_ast	*parser(t_token **tokens, t_gc **head)
{
	t_ast	*left;

	if (tokens && (*tokens)->type != WORD)
	{
		print(2, "syntax error\n");
		return (NULL);
	}
	left = parse_pipeline(tokens, head);
	if (!left)
		return (NULL);
	while (*tokens && ((*tokens)->type == AND || (*tokens)->type == OR))
	{
		if (sub_parser(tokens, &left, head))
			return (NULL);
	}
	return (left);
}
