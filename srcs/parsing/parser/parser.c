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

static t_ast	*parse_pipeline(t_token **tokens, t_gc **head)
{
	t_ast	*pipe_node;
	t_ast	**commands;
	t_ast	*left;
	t_ast	*right;
	int		i;

	pipe_node = gc_malloc(sizeof(t_ast), head);
	if (!pipe_node)
		return (NULL);
	pipe_node->type = NODE_PIPE;
	pipe_node->u_data.s_pipe.cmd_count = 1;
	commands = (t_ast **)gc_malloc_array(sizeof(t_ast *) * 4, head);
	if (!commands)
		return (NULL);
	pipe_node->u_data.s_pipe.commands = commands;
	//
	left = parse_primary(tokens, head);
	if (!left)
		return (NULL);
	i = 0;
	commands[i++] = left;
	while (*tokens && (*tokens)->type == PIPE)
	{
		*tokens = (*tokens)->next;
		if (*tokens && (*tokens)->type != WORD)
		{
			print(2, "syntax error\n");
			return (NULL);
		}
		right = parse_primary(tokens, head);
		if (!right)
			return (NULL);
		commands[i++] = right;
		pipe_node->u_data.s_pipe.cmd_count++;
	}
	return (pipe_node);
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
