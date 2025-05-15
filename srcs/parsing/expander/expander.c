/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:18 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/15 21:10:01 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_var_char(char c, int pos)
{
	if (pos == 0)
		return (isalpha(c) || c == '_');
	return (isalnum(c) || c == '_');
}

static int	sub_get_expand_len(char *word, int *i, int *len, t_context *ctx)
{
	int		start;
	char	*var_name;
	char	*val;

	(*i)++;
	start = (*i);
	while (is_valid_var_char(word[(*i)], (*i)))
		(*i)++;
	var_name = gc_strndup(&word[start], (*i) - start, ctx->head);
	if (!var_name)
		return (1);
	if (*i == start && word[(*i)] == '?')
		(*len) += ft_intlen(ctx->last_exit_status);
	else if (*i == start && word[(*i)] == '$')
		(*len) += ft_intlen(getpid());
	else
	{
		val = getenv(var_name);
		if (val)
			(*len) += ft_strlen(val);
	}
	gc_free(var_name, ctx->head);
	return (0);
}

int	get_expand_len(char *word, t_context *ctx)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	while (word[i])
	{
		if (word[i] == '$' && word[i + 1])
		{
			if (isdigit(word[i + 1]))
			{
				if (ctx->argc > ft_atoi(&word[i + 1]))
					len += ft_strlen(ctx->argv[ft_atoi(&word[i + 1])]);
				i += 2;
			}
			else if (sub_get_expand_len(word, &i, &len, ctx))
				return (-1);
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

int	expand_tilde(char **word, t_gc **head)
{
	char	*home;
	char	*result;
	int		len_home;
	int		len_result;

	if ((*word)[0] != '~')
		return (0);
	if ((*word)[1] && (*word)[1] != '/' && !isspace((*word)[1]))
		return (0);
	home = getenv("HOME");
	if (!home)
	{
		print(2, "getenv: HOME not set\n");
		return (1);
	}
	len_home = ft_strlen(home);
	len_result = len_home + ft_strlen(&(*word)[1]);
	result = gc_malloc(len_result + 1, head);
	if (!result)
		return (1);
	ft_strlcpy(result, home, len_home + 1);
	ft_strlcat(result, &(*word)[1], len_result + 1);
	gc_free(word, head);
	(*word) = result;
	return (0);
}

int	expander(t_token **tokens, t_context *ctx)
{
	t_token	*cur;
	int		len_value_expanded;

	cur = *tokens;
	while (cur)
	{
		if (cur->type == WORD && cur->quote != SINGLE_QUOTE && cur->value)
		{
			if (cur->quote == NO_QUOTE && expand_tilde(&cur->value, ctx->head))
				return (1);
			len_value_expanded = get_expand_len(cur->value, ctx);
			if (len_value_expanded < 0)
				return (1);
			if (expand_one_token(&cur->value, len_value_expanded, ctx))
				return (1);
		}
		if (cur->type == REDIR_HEREDOC)
		{
			if (cur->next && cur->next->type == WORD)
				cur = cur->next;
		}
		cur = cur->next;
	}
	return (0);
}
