/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:07:21 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 15:30:27 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	wildcard_replace(t_token *tok, t_token **wildcard_tok, char **files)
{
	t_context	*ctx;
	t_token		*tmp;
	int			i;

	ctx = get_ptr();
	(*wildcard_tok) = NULL;
	tmp = NULL;
	i = 0;
	while (files[i])
	{
		if (!is_file_needed(tok, files[i]))
		{
			i++;
			continue ;
		}
		tmp = new_token(WORD, NO_QUOTE, files[i], ctx->head);
		if (!tmp)
			return (1);
		token_add_back(wildcard_tok, tmp);
		i++;
	}
	return (0);
}

static int	sub_wildcard(t_token **tok, t_token **curr, t_token **prev,
		char **files)
{
	t_token	*wildcard_tok;
	t_token	*next;

	if ((*curr)->type == WORD && (*curr)->quote == NO_QUOTE)
	{
		if (ft_strchr((*curr)->value, '*'))
		{
			if (wildcard_replace(*curr, &wildcard_tok, files))
				return (1);
			if (!wildcard_tok)
				return (0);
			if ((*prev))
				(*prev)->next = wildcard_tok;
			else
				*tok = wildcard_tok;
			next = (*curr)->next;
			(*curr) = wildcard_tok;
			while ((*curr)->next)
				(*curr) = (*curr)->next;
			(*curr)->next = next;
		}
	}
	return (0);
}

int	wildcard(t_token **tok, t_gc **head)
{
	t_token	*prev;
	t_token	*curr;
	char	**files;

	files = NULL;
	if (get_wildcard(&files, head))
		return (1);
	if (!files)
		return (0);
	prev = NULL;
	curr = *tok;
	while (curr)
	{
		if (sub_wildcard(tok, &curr, &prev, files))
			return (1);
		prev = curr;
		curr = curr->next;
	}
	return (0);
}
