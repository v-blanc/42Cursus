#include "../../include/minishell.h"

int	parse_master(char *input, t_token **tokens, t_context *context, t_gc **head)
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
	t_token	*tokens;

	tokens = NULL;
	printf("\ninput: %s\n", input);
	if (parse_master(input, &tokens, context, head))
		return (1);
	while (tokens)
	{
		printf("Expanded: type=%d, value=`%s`\n", tokens->type, tokens->value);
		tokens = tokens->next;
	}
	printf("\n");
	return (0);
}
