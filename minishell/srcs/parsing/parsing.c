/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:35:46 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 13:43:01 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
				print(2, "minishell: Missing opening parenthesis\n");
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
			print(2, "minishell: Missing closing parenthesis\n");
		else if (quote)
			print(2, "minishell: Missing closing quote `%c`\n", quote);
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
	if (catch_syntax_error(*tokens, ctx))
		return (1);
	if (expander(tokens, *ctx))
		return (1);
	if (merge_tokens(tokens, (*ctx)->head))
		return (1);
	if (wildcard(tokens, (*ctx)->head))
		return (1);
	return (0);
}

int	parsing(char *input, t_ast **ast, t_context **ctx)
{
	t_token	*tokens_head;
	t_token	*tokens;

	if (!input || (input && (input[0] == '\0' || input[0] == '\n')))
		return (0);
	tokens_head = NULL;
	if (full_tokenize(input, &tokens_head, ctx))
		return (1);
	tokens = tokens_head;
	*ast = parser(&tokens, ctx);
	if (!(*ast))
		return (1);
	return (0);
}
