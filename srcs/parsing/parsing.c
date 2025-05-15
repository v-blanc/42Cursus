/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:46 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/15 13:52:22 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sub_is_valid_input(const char **line, char *quote, int *paren,
		t_context **ctx)
{
	if ((**line == '\'' || **line == '"'))
	{
		if ((*quote) == 0)
			(*quote) = **line;
		else if ((*quote) == **line)
			(*quote) = 0;
	}
	else if (!(*quote))
	{
		if (**line == '(')
			(*paren)++;
		else if (**line == ')')
		{
			if ((*paren) == 0)
			{
				print(2, "Missing opening parenthesis\n");
				(*ctx)->last_exit_status = 2;
				return (1);
			}
			(*paren)--;
		}
	}
	(*line)++;
	return (0);
}

static int	is_valid_input(const char *line, t_context **ctx)
{
	int		paren;
	char	quote;

	paren = 0;
	quote = 0;
	while (*line)
	{
		if (sub_is_valid_input(&line, &quote, &paren, ctx))
			return (1);
	}
	if (quote || paren)
	{
		if (paren)
			print(2, "Missing closing parenthesis\n");
		else if (quote)
			print(2, "Missing closing quote `%c`\n", quote);
		(*ctx)->last_exit_status = 2;
		return (1);
	}
	return (0);
}

static int	full_tokenize(char *input, t_token **tokens, t_context **ctx)
{
	if (is_valid_input(input, ctx))
		return (1);
	if (tokenizer(tokens, input, ctx))
		return (1);
	if (expander(tokens, *ctx))
		return (1);
	if (merge_tokens(tokens, (*ctx)->head))
		return (1);
	return (0);
}

static int	check_void_paren(t_token *tok, t_context **ctx)
{
	while (tok)
	{
		if (tok->type == PAREN_OPEN && tok->next
			&& tok->next->type == PAREN_CLOSE)
		{
			print(2, "syntax error\n");
			(*ctx)->last_exit_status = 2;
			return (1);
		}
		tok = tok->next;
	}
	return (1);
}

int	parsing(char *input, t_ast **ast, t_context **ctx)
{
	t_token	*tokens_head;
	t_token	*tokens;

	if (!input || (input && (input[0] == '\0' || input[0] == '\n')))
		return (0);
	tokens = NULL;
	if (full_tokenize(input, &tokens, ctx))
		return (1);
	tokens_head = tokens;
	if (check_void_paren(tokens, ctx))
		return (1);
	*ast = parser(&tokens_head, ctx);
	if (!(*ast))
		return (1);
	return (0);
}
