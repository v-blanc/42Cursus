/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:23 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/16 15:37:59 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmd_args(t_token *tok)
{
	int	count;

	if (!tok)
		return (0);
	if (tok && (tok->type != WORD && !is_redirection(tok->type)))
		return (-1);
	count = 0;
	while (tok && (tok->type == WORD || is_redirection(tok->type)))
	{
		if (is_redirection(tok->type))
		{
			tok = tok->next;
			if (tok)
				tok = tok->next;
		}
		else if (tok->type == WORD)
		{
			count++;
			tok = tok->next;
		}
		else
			tok = tok->next;
	}
	return (count);
}

int	count_cmd_redir(t_token *tok)
{
	int	count;

	if (!tok)
		return (0);
	if (tok && (tok->type != WORD && !is_redirection(tok->type)))
		return (-1);
	count = 0;
	while (tok && (tok->type == WORD || is_redirection(tok->type)))
	{
		if (is_redirection(tok->type))
		{
			if (!tok->next || tok->next->type != WORD)
				return (-1);
			count++;
			tok = tok->next->next;
		}
		else
			tok = tok->next;
	}
	return (count);
}
