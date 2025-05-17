/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:07:21 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/17 20:02:35 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	wildcard_replace(t_token *tok, t_token **wildcard_tok, char **files,
		t_gc **head)
{
	t_token	*tmp;
	int		i;

	(void)tok;
	(*wildcard_tok) = NULL;
	tmp = NULL;
	i = 0;
	while (files[i])
	{
		tmp = new_token(WORD, NO_QUOTE, files[i], head);
		if (!tmp)
			return (1);
		token_add_back(wildcard_tok, tmp);
		i++;
	}
	return (0);
}

int	wildcard(t_token **tok, t_gc **head)
{
	t_token	*prev;
	t_token	*curr;
	t_token	*next;
	t_token	*wildcard_tok;
	char	**files;

	files = NULL;
	if (get_wildcard(&files, head))
		return (1);
	if (!files)
		return (0);
	prev = NULL;
	curr = *tok;
	(void)next;
	while (curr)
	{
		if (curr->type == WORD && curr->quote == NO_QUOTE)
		{
			if (ft_strchr(curr->value, '*'))
			{
				if (wildcard_replace(*tok, &wildcard_tok, files, head))
					return (1);
				if (prev)
					prev->next = wildcard_tok;
				else
					*tok = wildcard_tok;
				next = curr->next;
				curr = wildcard_tok;
				while (curr->next)
					curr = curr->next;
				curr->next = next;
			}
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}
