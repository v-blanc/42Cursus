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

static int	pipe_cmd_count(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type == PIPE)
	{
		count++;
		tokens = tokens->next;
		while (tokens && tokens->type == WORD)
			tokens = tokens->next;
	}
	return (count);
}

static int	init_pipe_node(t_ast **pipe_node, int cmd_count, t_gc **head)
{
	t_ast	**commands;

	(*pipe_node) = gc_malloc(sizeof(t_ast), head);
	if (!pipe_node)
		return (1);
	(*pipe_node)->type = NODE_PIPE;
	(*pipe_node)->u_data.s_pipe.cmd_count = 1;
	commands = (t_ast **)gc_malloc_array(sizeof(t_ast *) * cmd_count, head);
	if (!commands)
		return (1);
	(*pipe_node)->u_data.s_pipe.commands = commands;
	return (0);
}

static int	sub_parse_pipeline(t_token **tokens, t_ast **pipe_node, int *i,
		t_gc **head)
{
	t_ast	*curr_cmd;

	*tokens = (*tokens)->next;
	if (*tokens && (*tokens)->type != WORD)
	{
		print(2, "syntax error\n");
		return (1);
	}
	curr_cmd = parse_primary(tokens, head);
	if (!curr_cmd)
		return (1);
	(*pipe_node)->u_data.s_pipe.commands[(*i)++] = curr_cmd;
	(*pipe_node)->u_data.s_pipe.cmd_count++;
	return (0);
}

t_ast	*parse_pipeline(t_token **tokens, t_gc **head)
{
	t_ast	*pipe_node;
	t_ast	*first_cmd;
	int		i;

	first_cmd = parse_primary(tokens, head);
	if (!first_cmd)
		return (NULL);
	if (!*tokens || (*tokens)->type != PIPE)
		return (first_cmd);
	if (init_pipe_node(&pipe_node, pipe_cmd_count(*tokens), head))
		return (NULL);
	i = 0;
	pipe_node->u_data.s_pipe.commands[i++] = first_cmd;
	while (*tokens && (*tokens)->type == PIPE)
	{
		if (sub_parse_pipeline(tokens, &pipe_node, &i, head))
			return (NULL);
	}
	return (pipe_node);
}
