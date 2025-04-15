#include "minishell.h"

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
				print(2, "Missing opening parenthesis\n");
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
			print(2, "Missing closing parenthesis\n");
		if (quote)
			print(2, "Missing closing quote `%c`\n", quote);
		return (1);
	}
	return (0);
}

static int	full_tokenize(char *input, t_token **tokens, t_context *context,
		t_gc **head)
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

static int	testing_parser_debug(char *input, t_context **context, t_gc **head)
{
	t_token	*tokens_head;
	t_token	*tokens;
	t_ast	*ast;

	return (0);
	if (!input || (input && (input[0] == '\0' || input[0] == '\n')))
		return (0);
	testing_parser_debug(input, context, head);
	tokens = NULL;
	tokens_head = tokens;
	printf("\ninput: %s\n\n", input);
	if (full_tokenize(input, &tokens, *context, head))
		return (1);
	while (tokens)
	{
		printf("Expanded: type=%d, value=`%s`\n", tokens->type, tokens->value);
		tokens = tokens->next;
	}
	printf("\n");
	printf("Parser:\n");
	ast = parser(&tokens_head, head);
	if (!ast)
		return (1);
	print_ast(ast, 0);
	printf("\nExecution:\n\n```\n");
	if (ast->type == NODE_CMD)
		exec_manager(ast, context);
	printf("```\n\n");
	return (0);
}

int	parsing(char *input, t_context **context, t_gc **head)
{
	t_token	*tokens_head;
	t_token	*tokens;
	t_ast	*ast;

	testing_parser_debug(input, context, head); // TODO: remove
	if (!input || (input && (input[0] == '\0' || input[0] == '\n')))
		return (0);
	tokens = NULL;
	if (full_tokenize(input, &tokens, *context, head))
		return (1);
	tokens_head = tokens;
	ast = parser(&tokens_head, head);
	if (!ast)
		return (1);
	if (ast->type == NODE_CMD)
		exec_manager(ast, context);
	return (0);
}
