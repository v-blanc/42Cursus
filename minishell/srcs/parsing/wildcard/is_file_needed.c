/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_needed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:08:58 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/20 15:13:53 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	update_vars(int *start_index, int *match, int *i, int *j)
{
	if (*start_index != -1)
	{
		*i = *start_index + 1;
		*j = ++(*match);
		return (0);
	}
	else
		return (1);
}

static int	sub_is_file_needed(t_token *tok, char *file, int *i, int *j)
{
	const int	len_file = ft_strlen(file);
	const int	len_tok = ft_strlen(tok->value);
	int			start_index;
	int			match;

	start_index = -1;
	match = 0;
	while (*j < len_file)
	{
		if (*i < len_tok && (tok->value[*i] == file[*j]))
		{
			(*i)++;
			(*j)++;
		}
		else if (*i < len_tok && tok->value[*i] == '*')
		{
			start_index = (*i)++;
			match = *j;
		}
		else if (update_vars(&start_index, &match, i, j))
			return (*i == len_tok);
	}
	while (*i < len_tok && tok->value[*i] == '*')
		(*i)++;
	return (*i == len_tok);
}

bool	is_file_needed(t_token *tok, char *file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	return (sub_is_file_needed(tok, file, &i, &j));
}
