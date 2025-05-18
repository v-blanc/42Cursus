/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:26:34 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 14:49:23 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_input.h"

static int	set_readline_hook(void)
{
	t_context	*ctx;

	ctx = get_ptr();
	if (ctx->signal)
		rl_done = 1;
	return (!rl_done);
}

void	set_input(t_context **ctx)
{
	t_ast	*ast;
	char	*input;
	char	*rl_prompt;

	rl_event_hook = set_readline_hook;
	while (true)
	{
		create_aliases(*ctx);
		rl_prompt = set_readline_prompt(*ctx);
		if (rl_prompt == NULL)
		{
			gc_free_all((*ctx)->head);
			continue ;
		}
		input = readline(rl_prompt);
		rl_done = 0;
		if ((*ctx)->signal)
		{
			(*ctx)->last_exit_status = (*ctx)->signal;
			(*ctx)->signal = 0;
			continue ;
		}
		if (!is_valid_rl_input(input, ctx))
		{
			free(input);
			continue ;
		}
		add_history(input);
		ast = NULL;
		if (parsing(input, &ast, ctx))
		{
			free(input);
			gc_free_all((*ctx)->head);
			continue ;
		}
		free(input);
		printf("\n******************************************\n");
		print_ast(ast, 0);
		printf("\n******************************************\n\n");
		execute_ast(ast, *ctx);
		if ((*ctx)->signal)
		{
			(*ctx)->last_exit_status = (*ctx)->signal;
			(*ctx)->signal = 0;
		}
		refresh((*ctx)->backup_fds);
		gc_free_all((*ctx)->head);
	}
}
