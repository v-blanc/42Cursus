/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:26:34 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/21 14:40:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_input.h"

extern bool	g_sigint;
extern bool	g_was_in_heredoc;

int	set_readline_hook(void)
{
	if (g_sigint && g_was_in_heredoc)
	{
		g_was_in_heredoc = false;
		return (0);
	}
	if (g_sigint)
		rl_done = 1;
	return (0);
}

static int	get_user_input(char **input, t_context **ctx)
{
	char	*rl_prompt;

	if (isatty(STDIN_FILENO))
		refresh((*ctx)->backup_fds);
	rl_prompt = set_readline_prompt(*ctx);
	if (rl_prompt == NULL)
	{
		gc_free_all((*ctx)->head);
		return (1);
	}
	(*input) = readline(rl_prompt);
	if (g_sigint)
	{
		free(*input);
		(*ctx)->last_exit_status = 130;
		g_sigint = false;
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

static void	cleanup_set_input(t_ast *ast, t_context **ctx)
{
	if (g_sigint)
	{
		(*ctx)->last_exit_status = 130;
		g_sigint = false;
	}
	close_heredoc_fds(ast);
	close((*ctx)->cmd_backup_fds[STDIN_FILENO]);
	close((*ctx)->cmd_backup_fds[STDOUT_FILENO]);
	refresh((*ctx)->backup_fds);
	gc_free_all((*ctx)->head);
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
		cleanup_set_input(ast, ctx);
	}
}
