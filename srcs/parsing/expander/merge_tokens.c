/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:20 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/06 11:08:52 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sub_merge_tokens(t_token *curr, t_token *next, t_gc **head)
{
	char	*joined;
	int		len_curr_value;
	int		len_joined;

	if (curr->type == WORD && next->type == WORD && curr->joined_next)
	{
		len_curr_value = ft_strlen(curr->value);
		len_joined = len_curr_value + ft_strlen(next->value);
		joined = gc_malloc(len_joined + 1, head);
		if (!joined)
			return (1);
		if (curr->value[len_curr_value - 1] == '$' && next->quote != NO_QUOTE)
			ft_strlcpy(joined, curr->value, len_curr_value);
		else
			ft_strlcpy(joined, curr->value, len_curr_value + 1);
		ft_strlcat(joined, next->value, len_joined + 1);
		gc_free(curr->value, head);
		curr->value = joined;
		curr->quote = next->quote;
		curr->joined_next = next->joined_next;
		curr->next = next->next;
		gc_free(next, head);
	}
	return (0);
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
		if (curr->type == WORD && curr->quote == NO_QUOTE
			&& !ft_strlen(curr->value))
		{
			if (prev)
				prev->next = next;
			else
				*tokens = next;
		}
		if (!next)
			break ;
		if (sub_merge_tokens(curr, next, head))
			return (1);
		prev = curr;
		curr = next;
	}
	return (0);
}
