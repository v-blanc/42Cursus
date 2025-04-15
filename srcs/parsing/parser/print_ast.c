#include "minishell.h"

void	print_indent(int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		printf("\t");
		i++;
	}
}

void	print_ast(t_ast *node, int depth)
{
	if (!node)
		return ;
	print_indent(depth);
	switch (node->type)
	{
	case NODE_CMD:
		printf("NODE_CMD\n");
		print_indent(depth + 1);
		printf("argv: ");
		for (int i = 0; node->u_data.s_cmd.args
			&& node->u_data.s_cmd.args[i]; i++)
			printf("'%s' ", node->u_data.s_cmd.args[i]);
		printf("\n");
		if (node->u_data.s_cmd.redir_count > 0)
		{
			print_indent(depth + 1);
			printf("redirections:\n");
			for (int i = 0; node->u_data.s_cmd.redirs[i]; i++)
			{
				print_ast(node->u_data.s_cmd.redirs[i], depth + 2);
			}
		}
		break ;
	case NODE_REDIR:
		printf("NODE_REDIR\n");
		print_indent(depth + 1);
		printf("op: %d\n", node->u_data.s_red.op);
		print_indent(depth + 1);
		printf("fd_source: %d\n", node->u_data.s_red.fd_source);
		print_indent(depth + 1);
		printf("target: %s\n", node->u_data.s_red.target);
		break ;
	case NODE_PIPE:
		printf("NODE_PIPE\n");
		for (int i = 0; node->u_data.s_pipe.commands[i]; i++)
		{
			print_ast(node->u_data.s_pipe.commands[i], depth + 1);
		}
		break ;
	case NODE_BINARY_OP:
		printf("NODE_BINARY_OP (%s)\n",
			node->u_data.s_op.op == AND ? "&&" : "||");
		print_ast(node->u_data.s_op.left, depth + 1);
		print_ast(node->u_data.s_op.right, depth + 1);
		break ;
	default:
		print_indent(depth);
		printf("Unknown node type\n");
	}
}
