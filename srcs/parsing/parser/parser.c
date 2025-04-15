#include "minishell.h"

static t_ast	*parse_primary(t_token **tokens, t_gc **head)
{
	t_ast	*node;

	if (*tokens && (*tokens)->type == PAREN_OPEN)
	{
		*tokens = (*tokens)->next;
		node = parser(tokens, head);
		if (!node)
			return (NULL);
		if (!*tokens || (*tokens)->type != PAREN_CLOSE)
			return (NULL);
		*tokens = (*tokens)->next;
		return (node);
	}
	else
		return (parse_command(tokens, head));
}

static int	sub_parse_pipeline(t_token **tokens, t_ast **left, t_gc **head)
{
	t_ast	*right;
	t_ast	*pipe_node;
	t_ast	**commands;

	*tokens = (*tokens)->next;
	if (*tokens && (*tokens)->type != WORD)
	{
		print(2, "syntax error\n");
		return (1);
	}
	right = parse_primary(tokens, head);
	pipe_node = gc_malloc(sizeof(t_ast), head);
	if (!right || !pipe_node)
		return (1);
	pipe_node->type = NODE_PIPE;
	pipe_node->u_data.s_pipe.cmd_count = 2;
	commands = (t_ast **)gc_malloc_array(sizeof(t_ast *) * 2, head);
	pipe_node->u_data.s_pipe.commands = commands;
	if (!pipe_node->u_data.s_pipe.commands)
		return (1);
	pipe_node->u_data.s_pipe.commands[0] = *left;
	pipe_node->u_data.s_pipe.commands[1] = right;
	*left = pipe_node;
	return (0);
}

static t_ast	*parse_pipeline(t_token **tokens, t_gc **head)
{
	t_ast	*left;

	left = parse_primary(tokens, head);
	if (!left)
		return (NULL);
	while (*tokens && (*tokens)->type == PIPE)
	{
		if (sub_parse_pipeline(tokens, &left, head))
			return (NULL);
	}
	return (left);
}

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
