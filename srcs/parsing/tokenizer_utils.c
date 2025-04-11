#include "../../include/minishell.h"

int	is_operator_char(char c)
{
	return (c == '|' || c == '&' || c == '>' || c == '<' || c == '('
		|| c == ')');
}

static int	get_operator_len(t_token_type type)
{
	if (type == AND || type == OR || type == REDIR_APPEND
		|| type == REDIR_HEREDOC)
		return (2);
	else if (type == END)
		return (0);
	else
		return (1);
}

t_token_type	get_op_type(const char *s, int *len)
{
	t_token_type	type;

	if (s[0] == '&' && s[1] == '&')
		type = AND;
	else if (s[0] == '|' && s[1] == '|')
		type = OR;
	else if (s[0] == '>' && s[1] == '>')
		type = REDIR_APPEND;
	else if (s[0] == '<' && s[1] == '<')
		type = REDIR_HEREDOC;
	else if (s[0] == '>')
		type = REDIR_OUT;
	else if (s[0] == '<')
		type = REDIR_IN;
	else if (s[0] == '|')
		type = PIPE;
	else if (s[0] == '(')
		type = PAREN_OPEN;
	else if (s[0] == ')')
		type = PAREN_CLOSE;
	else
		type = END;
	*len = get_operator_len(type);
	return (type);
}

t_token	*new_token(t_token_type type, char quote_type, const char *value,
		t_gc **head)
{
	t_token	*token;

	token = gc_malloc(sizeof(t_token), head);
	if (!token)
		return (NULL);
	token->type = type;
	if (quote_type == '\'')
		token->quote = SINGLE_QUOTE;
	else if (quote_type == '"')
		token->quote = DOUBLE_QUOTE;
	else
		token->quote = NO_QUOTE;
	token->value = NULL;
	if (type == WORD && value)
	{
		token->value = gc_strdup(value, head);
		if (!token->value)
		{
			gc_free(token, head);
			return (NULL);
		}
	}
	token->joined_next = 0;
	token->next = NULL;
	return (token);
}

void	token_add_back(t_token **tokens, t_token *new)
{
	t_token	*tmp;

	if (!tokens || !new)
		return ;
	if (!*tokens)
	{
		*tokens = new;
		return ;
	}
	tmp = *tokens;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
