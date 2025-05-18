/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_needed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:08:58 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 13:42:43 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	update_vars(int *start_index, int *match, int *i, int j)
{
	*start_index = (*i)++;
	*match = j;
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
			update_vars(&start_index, &match, i, *j);
		else if (start_index != -1)
		{
			*i = start_index + 1;
			*j = ++match;
		}
		else
			return (*i == len_tok);
	}
	return (-1);
}

bool	is_file_needed(t_token *tok, char *file)
{
	const int	len_tok = ft_strlen(tok->value);
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (sub_is_file_needed(tok, file, &i, &j) == -1)
		return (i == len_tok);
	while (i < len_tok && tok->value[i] == '*')
		i++;
	return (i == len_tok);
}
