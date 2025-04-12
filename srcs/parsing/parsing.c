#include "../../include/minishell.h"

int	parsing(char *input, t_token **tokens, t_context *context, t_gc **head)
{
	if (tokenizer(tokens, input, head))
		return (1);
	if (expander(tokens, context, head))
		return (1);
	if (merge_tokens(tokens, head))
		return (1);
	return (0);
}

int	testing_parser(char *input, t_context *context, t_gc **head)
{
	t_token	*tokens_head;
	t_token	*tokens;
	t_ast	*ast;

	tokens = NULL;
	printf("\ninput: %s\n\n", input);
	if (parsing(input, &tokens, context, head))
		return (1);
	tokens_head = tokens;
	while (tokens)
	{
		printf("Expanded: type=%d, value=`%s`\n", tokens->type, tokens->value);
		tokens = tokens->next;
	}
	printf("\n");
	// tokens = tokens_head;
	printf("Parser:\n");
	ast = parser(&tokens_head, head);
	if (ast)
		print_ast(ast, 0);
	printf("\n");
	return (0);
}
