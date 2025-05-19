/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:43 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/19 15:42:34 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*parse_quoted_word(const char *s, int *i, t_gc **head)
{
	char	quote;
	char	*buf;
	int		j;

	quote = s[*i];
	(*i)++;
	buf = gc_malloc(ft_strlen(&s[*i]) + 1, head);
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

	buf = gc_malloc(ft_strlen(&s[*i]) + 1, head);
	if (!buf)
		return (NULL);
	j = 0;
	while (s[*i] && !ft_isspace((unsigned char)s[*i])
		&& !is_operator_char(s[*i]) && s[*i] != '\'' && s[*i] != '"')
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
	if (!(*tok))
		return (1);
	if (s[*i] && !ft_isspace((unsigned char)s[*i]) && !is_operator_char(s[*i]))
		(*tok)->joined_next = 1;
	return (0);
}

static int	handle_error(t_token *tok, const char *s, int *i, int len)
{
	t_context	*ctx;

	if (!tok)
		return (1);
	if (tok->type == END)
	{
		if (s[*i])
		{
			print(2, "minishell: syntax error near unexpected token  `&'\n");
			ctx = get_ptr();
			ctx->last_exit_status = 2;
			return (1);
		}
		(*i)++;
		return (0);
	}
	(*i) += len;
	return (0);
}

int	tokenizer(t_token **tokens, const char *s, t_context **ctx)
{
	t_token	*tok;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace((unsigned char)s[i]))
			i++;
		if (!s[i])
			break ;
		if (is_operator_char(s[i]))
		{
			tok = new_token(get_op_type(&s[i], &len), 0, NULL, (*ctx)->head);
			if (handle_error(tok, s, &i, len))
				return (1);
		}
		else if (sub_tokenizer(s, &i, &tok, (*ctx)->head))
			return (1);
		if (!tok)
			return (1);
		token_add_back(tokens, tok);
	}
	return (0);
}
