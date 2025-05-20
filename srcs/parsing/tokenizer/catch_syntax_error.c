/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:24:59 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/20 12:49:58 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	sub_print_syntax_error(char *type_str, t_context **ctx)
{
	if (!type_str)
		return (1);
	print(2, "minishell: syntax error near unexpected token `%s'\n", type_str);
	(*ctx)->last_exit_status = 2;
	return (1);
}

static int	print_syntax_error(t_token_type type, t_context **ctx)
{
	char	*type_str;

	if (type == PAREN_OPEN)
		type_str = gc_strdup("(", (*ctx)->head);
	else if (type == PAREN_CLOSE)
		type_str = gc_strdup(")", (*ctx)->head);
	else if (type == PIPE)
		type_str = gc_strdup("|", (*ctx)->head);
	else if (type == REDIR_IN)
		type_str = gc_strdup("<", (*ctx)->head);
	else if (type == REDIR_OUT)
		type_str = gc_strdup(">", (*ctx)->head);
	else if (type == REDIR_APPEND)
		type_str = gc_strdup(">>", (*ctx)->head);
	else if (type == REDIR_HEREDOC)
		type_str = gc_strdup("<<", (*ctx)->head);
	else if (type == AND)
		type_str = gc_strdup("&&", (*ctx)->head);
	else if (type == OR)
		type_str = gc_strdup("||", (*ctx)->head);
	else
		type_str = gc_strdup("newline", (*ctx)->head);
	return (sub_print_syntax_error(type_str, ctx));
}

static int	check_left_and_right(t_token *t, t_token *prev, t_context **ctx)
{
	if (!prev || (prev->type != WORD && !is_redirection(t->next->type)
			&& prev->type != PAREN_CLOSE))
		return (print_syntax_error(t->type, ctx));
	if (!t->next)
		return (print_syntax_error(t->type, ctx));
	if (t->next->type != WORD && !is_redirection(t->next->type)
		&& t->next->type != PAREN_OPEN)
		return (print_syntax_error(t->next->type, ctx));
	return (0);
}

static int	check_redir(t_token *t, t_context **ctx)
{
	if (!t->next)
		return (print_syntax_error(END, ctx));
	if (t->next->type != WORD)
		return (print_syntax_error(t->next->type, ctx));
	return (0);
}

int	catch_syntax_error(t_token *t, t_context **ctx)
{
	t_token	*prev;

	prev = NULL;
	while (t)
	{
		if (t->type == PAREN_OPEN && t->next && t->next->type != WORD
			&& !is_redirection(t->next->type) && t->next->type != PAREN_OPEN)
			return (print_syntax_error(t->type, ctx));
		else if ((t->type == AND || t->type == OR) && check_left_and_right(t,
				prev, ctx))
			return (1);
		else if (t->type == PIPE && check_left_and_right(t, prev, ctx))
			return (1);
		else if (is_redirection(t->type) && check_redir(t, ctx))
			return (1);
		else if (t->type == WORD && t->next && t->next->type == PAREN_OPEN)
			return (print_syntax_error(t->next->type, ctx));
		prev = t;
		t = t->next;
	}
	return (0);
}
