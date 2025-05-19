/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_tokenizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:47:14 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/19 18:39:33 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*parse_word(const char *s, int *i, t_gc **head)
{
	char	*buf;
	int		j;

	buf = gc_malloc(ft_strlen(&s[*i]) + 1, head);
	if (!buf)
		return (NULL);
	j = 0;
	while (s[*i] && !ft_isspace((unsigned char)s[*i]) && s[*i] != '\''
		&& s[*i] != '"')
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

static int	sub_tokenizer_heredoc(const char *s, int *i, t_token **tok,
		t_gc **head)
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
	if (s[*i] && !ft_isspace((unsigned char)s[*i]))
		(*tok)->joined_next = 1;
	return (0);
}

int	heredoc_tokenizer(t_token **tks, const char *s, t_gc **gc)
{
	t_token	*tok;
	int		i;

	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace((unsigned char)s[i]))
			i++;
		if (!s[i])
			break ;
		else if (sub_tokenizer_heredoc(s, &i, &tok, gc))
			return (1);
		if (!tok)
			return (1);
		token_add_back(tks, tok);
	}
	return (0);
}
