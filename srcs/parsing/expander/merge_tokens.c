/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:20 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/15 17:46:31 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sub_merge_tokens(t_token **curr, t_token *next, t_gc **head)
{
	char	*joined;
	int		len_curr_value;
	int		len_joined;

	len_curr_value = ft_strlen((*curr)->value);
	len_joined = len_curr_value + ft_strlen(next->value);
	joined = gc_malloc(len_joined + 1, head);
	if (!joined)
		return (1);
	if ((*curr)->value[len_curr_value - 1] == '$' && next->quote != NO_QUOTE)
		ft_strlcpy(joined, (*curr)->value, len_curr_value);
	else
		ft_strlcpy(joined, (*curr)->value, len_curr_value + 1);
	ft_strlcat(joined, next->value, len_joined + 1);
	(*curr)->value = joined;
	if ((*curr)->quote == NO_QUOTE)
		(*curr)->quote = next->quote;
	(*curr)->joined_next = next->joined_next;
	(*curr)->next = next->next;
	return (0);
}

static void	handle_empty_token(t_token **tokens, t_token *prev, t_token *curr,
		t_token *next)
{
	if (curr->type == WORD && curr->quote == NO_QUOTE
		&& ft_strlen(curr->value) == 0)
	{
		if (prev)
			prev->next = next;
		else
			*tokens = next;
	}
}

int	merge_tokens(t_token **tokens, t_gc **head)
{
	t_token	*prev;
	t_token	*curr;
	t_token	*next;

	prev = NULL;
	curr = *tokens;
	while (curr)
	{
		next = curr->next;
		handle_empty_token(tokens, prev, curr, next);
		prev = curr;
		if (!next)
			break ;
		if (curr->type == WORD && next->type == WORD && curr->joined_next)
		{
			if (sub_merge_tokens(&curr, next, head))
				return (1);
		}
		else
			curr = curr->next;
	}
	return (0);
}
