#include "../../include/minishell.h"

static int	sub_is_valid_input(const char **line, char *quote, int *paren)
{
	if ((**line == '\'' || **line == '"'))
	{
		if ((*quote) == 0)
			(*quote) = **line;
		else if ((*quote) == **line)
			(*quote) = 0;
	}
	else if (!(*quote))
	{
		if (**line == '(')
			(*paren)++;
		else if (**line == ')')
		{
			if ((*paren) == 0)
			{
				printf("Missing opening parenthesis\n");
				return (1);
			}
			(*paren)--;
		}
	}
	(*line)++;
	return (0);
}

static int	is_valid_input(const char *line)
{
	int		paren;
	char	quote;

	paren = 0;
	quote = 0;
	while (*line)
	{
		if (sub_is_valid_input(&line, &quote, &paren))
			return (1);
	}
	if (quote || paren)
	{
		if (paren)
			printf("Missing closing parenthesis\n");
		if (quote)
			printf("Missing closing quote `%c`\n", quote);
		return (1);
	}
	return (0);
}

int	parsing(char *input, t_token **tokens, t_context *context, t_gc **head)
{
	if (is_valid_input(input))
		return (1);
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
