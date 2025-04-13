#include "../../../include/minishell.h"

static char	*parse_quoted_word(const char *s, int *i, t_gc **head)
{
	char	quote;
	char	*buf;
	int		j;

	quote = s[*i];
	(*i)++;
	buf = gc_malloc(strlen(&s[*i]) + 1, head);
	if (!buf)
		return (NULL);
	j = 0;
	while (s[*i] && s[*i] != quote)
	{
		if (s[*i] == '\\' && s[*i + 1])
		{
			buf[j++] = s[*i + 1];
			*i += 2;
		}
		else
			buf[j++] = s[(*i)++];
	}
	if (s[*i] == quote)
		(*i)++;
	buf[j] = '\0';
	return (gc_strndup(buf, j, head));
}

static char	*parse_word(const char *s, int *i, t_gc **head)
{
	char	*buf;
	int		j;

	buf = gc_malloc(strlen(&s[*i]) + 1, head);
	if (!buf)
		return (NULL);
	j = 0;
	while (s[*i] && !isspace((unsigned char)s[*i]) && !is_operator_char(s[*i])
		&& s[*i] != '\'' && s[*i] != '"')
	{
		if (s[*i] == '\\' && s[*i + 1])
		{
			buf[j++] = s[*i + 1];
			*i += 2;
		}
		else
			buf[j++] = s[(*i)++];
	}
	buf[j] = '\0';
	return (gc_strndup(buf, j, head));
}

static int	sub_tokenizer(const char *s, int *i, t_token **tok, t_gc **head)
{
	char	*val;
	char	quote_type;

	quote_type = 0;
	if (s[*i] == '\'' || s[*i] == '"')
	{
		quote_type = s[*i];
		val = parse_quoted_word(s, i, head);
	}
	else
		val = parse_word(s, i, head);
	if (!val)
		return (1);
	(*tok) = new_token(WORD, quote_type, val, head);
	if (s[*i] && !isspace((unsigned char)s[*i]) && !is_operator_char(s[*i]))
		(*tok)->joined_next = 1;
	return (0);
}

int	tokenizer(t_token **tokens, const char *s, t_gc **head)
{
	t_token	*tok;
	int		i;
	int		len;

	i = 0;
	while (s[i])
	{
		while (s[i] && isspace((unsigned char)s[i]))
			i++;
		if (!s[i])
			break ;
		if (is_operator_char(s[i]))
		{
			tok = new_token(get_op_type(&s[i], &len), 0, NULL, head);
			i += len;
		}
		else if (sub_tokenizer(s, &i, &tok, head))
			return (1);
		if (!tok)
			return (1);
		token_add_back(tokens, tok);
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_gc	*head;
// 	t_token	*token_head;
// 	t_token	*tokens;

// 	if (argc != 2)
// 		return (1);
// 	head = NULL;
// 	token_head = NULL;
// 	tokens = NULL;
// 	printf("input: %s\n", argv[1]);
// 	if (tokenizer(&tokens, argv[1], &head))
// 		return (1);
// 	token_head = tokens;
// 	while (tokens)
// 	{
// 		printf("Token: type=%d, quote=%d, joined_next=%d, value=`%s`\n",
// 			tokens->type, tokens->quote, tokens->joined_next, tokens->value);
// 		tokens = tokens->next;
// 	}
// 	if (merge_word_tokens(&tokens, &head))
// 		return (1);
// 	tokens = token_head;
// 	while (tokens)
// 	{
// 		printf("Merged: type=%d, value=`%s`\n", tokens->type, tokens->value);
// 		tokens = tokens->next;
// 	}
// 	gc_free_all(head);
// 	return (0);
// }
