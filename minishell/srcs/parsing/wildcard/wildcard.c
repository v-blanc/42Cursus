/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:07:21 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/21 12:06:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	wildcard_replace(t_token *tok, t_token **wildcard_tok, char **files,
		t_gc **head)
{
	t_token	*tmp;
	int		i;

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
		tmp = new_token(WORD, NO_QUOTE, files[i], head);
		if (!tmp)
			return (1);
		token_add_back(wildcard_tok, tmp);
		i++;
	}
	return (0);
}

static void	sub_sub_wildcard(t_token **curr, t_token *wildcard_tok)
{
	t_token	*next;

	next = (*curr)->next;
	(*curr) = wildcard_tok;
	while ((*curr)->next)
		(*curr) = (*curr)->next;
	(*curr)->next = next;
}

static int	sub_wildcard(t_token **tok, char **files, t_gc **head)
{
	t_token	*prev;
	t_token	*curr;
	t_token	*wildcard_tok;

	prev = NULL;
	curr = *tok;
	while (curr)
	{
		if (curr->type == WORD && curr->quote == NO_QUOTE
			&& ft_strchr(curr->value, '*'))
		{
			if (wildcard_replace(curr, &wildcard_tok, files, head))
				return (1);
			if (!wildcard_tok)
				return (0);
			if (prev)
				prev->next = wildcard_tok;
			else
				*tok = wildcard_tok;
			sub_sub_wildcard(&curr, wildcard_tok);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}

int	wildcard(t_token **tok, t_gc **head)
{
	char	**files;

	files = NULL;
	if (get_wildcard(&files, head))
		return (1);
	if (!files)
		return (0);
	if (sub_wildcard(tok, files, head))
		return (1);
	return (0);
}
