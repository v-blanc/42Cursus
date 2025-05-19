/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:26:34 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/19 19:43:11 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_input.h"

int	set_readline_hook(void)
{
	t_context	*ctx;

	ctx = get_ptr();
	if (ctx->signal)
		rl_done = 1;
	return (!rl_done);
}

static int	get_user_input(char **input, t_context **ctx)
{
	char	*rl_prompt;

	rl_prompt = set_readline_prompt(*ctx);
	if (rl_prompt == NULL)
	{
		gc_free_all((*ctx)->head);
		return (1);
	}
	(*input) = readline(rl_prompt);
	rl_done = 0;
	if ((*ctx)->signal)
	{
		free(*input);
		(*ctx)->last_exit_status = (*ctx)->signal;
		(*ctx)->signal = 0;
		return (1);
	}
	if (!is_valid_rl_input(*input, ctx))
	{
		free(*input);
		return (1);
	}
	add_history(*input);
	return (0);
}

static void	handle_signal(t_context **ctx)
{
	if ((*ctx)->signal)
	{
		(*ctx)->last_exit_status = (*ctx)->signal;
		(*ctx)->signal = 0;
	}
}

void	set_input(t_context **ctx)
{
	t_ast	*ast;
	char	*input;

	rl_event_hook = set_readline_hook;
	input = NULL;
	while (true)
	{
		init_sig();
		if (get_user_input(&input, ctx))
			continue ;
		ast = NULL;
		if (parsing(input, &ast, ctx) || !resolve_all_heredocs(ast, *ctx))
		{
			close_heredoc_fds(ast);
			free(input);
			gc_free_all((*ctx)->head);
			continue ;
		}
		free(input);
		execute_ast(ast, *ctx);
		close_heredoc_fds(ast);
		handle_signal(ctx);
		refresh((*ctx)->backup_fds);
		gc_free_all((*ctx)->head);
	}
}
