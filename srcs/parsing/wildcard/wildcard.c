/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:07:21 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/17 21:33:54 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_file_needed(t_token *tok, char *file)
{
	int	i;
	int	j;
	int	len_to_cmp;
	int	k;

	i = 0;
	j = 0;
	while (tok->value[i] && file[j])
	{
		printf("> &file[%d]: %s\n", j, &file[j]);
		printf("> &tok->value[%d]: %s\n", i, &tok->value[i]);
		if (tok->value[i] == '*')
		{
			printf("* found\n");
			while (tok->value[i] && tok->value[i] == '*')
				i++;
			printf("> new &tok->value[%d]: %s\n", i, &tok->value[i]);
			if (!tok->value[i])
			{
				printf("End of tok->value\n");
				return (1);
			}
			// while (file[j] && file[j] != tok->value[i])
			// 	j++;
			// printf("> new &file[%d]: %s\n", j, &file[j]);
			len_to_cmp = 0;
			k = i;
			while (tok->value[k] && tok->value[k++] != '*')
				len_to_cmp++;
			if (!len_to_cmp)
				return (1);
			printf("len_to_cmp: %d\n", len_to_cmp);
			if (found_last_match(&tok->value[i], &file[j], len_to_cmp))
			{
				i += len_to_cmp;
				j += len_to_cmp;
			}
		}
		else if (tok->value[i] != file[j])
		{
			printf("No match\n");
			return (0);
		}
		i++;
		j++;
		printf("\n");
	}
	return (0);
}

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
		printf("---------------------------------\n");
		if (!is_file_needed(tok, files[i]))
		{
			printf("Skipping file: %s\n\n", files[i]);
			i++;
			continue ;
		}
		tmp = new_token(WORD, NO_QUOTE, files[i], ctx->head);
		if (!tmp)
			return (1);
		token_add_back(wildcard_tok, tmp);
		printf("Adding file: %s\n\n", files[i]);
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
