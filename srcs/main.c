/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:46:57 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/16 23:38:30 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	refresh(int backup_fds[2])
{
	dup2(backup_fds[STDIN_FILENO], STDIN_FILENO);
	dup2(backup_fds[STDOUT_FILENO], STDOUT_FILENO);
	close(backup_fds[STDIN_FILENO]);
	close(backup_fds[STDOUT_FILENO]);
	backup_fds[STDIN_FILENO] = dup(STDIN_FILENO);
	backup_fds[STDOUT_FILENO] = dup(STDOUT_FILENO);
}

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

extern char	**environ;

int	init_environ(t_gc **head)
{
	char	*env_pwd;

	env_pwd = gc_malloc(PATH_MAX, head);
	if (environ == NULL || environ[0] == NULL)
	{
		environ = (char **)gc_malloc_array_perm(3, head);
		if (!environ)
			return (1);
		getcwd(env_pwd, PATH_MAX);
		if (!env_pwd)
		{
			print(2, "minishell: env error\n"); // TODO: update
			return (1);
		}
		environ[0] = gc_strjoin_perm("PWD=", env_pwd, head);
		environ[1] = gc_strjoin_perm("SHLVL=0", "", head);
		// TODO: change to use `which env` ou autre ?
		environ[2] = gc_strjoin_perm("_=/usr/bin/env", "", head);
		environ[3] = NULL;
		if (!environ[0] || !environ[1] || !environ[2])
			return (1);
	}
	return (0);
}

int	init_context(t_context **context, int argc, char **argv, t_gc **head)
{
	(*context) = gc_malloc_perm(sizeof(t_context), head);
	if (!(*context))
		return (1);
	set_ptr(*context);
	(*context)->argc = argc;
	(*context)->argv = argv;
	(*context)->last_exit_status = 0;
	(*context)->last_node_type = -1;
	(*context)->head = head;
	(*context)->orig_term = (struct termios){0};
	(*context)->backup_fds[STDIN_FILENO] = dup(STDIN_FILENO);
	(*context)->backup_fds[STDOUT_FILENO] = dup(STDOUT_FILENO);
	(*context)->signal = 0;
	tcgetattr(STDIN_FILENO, &(*context)->orig_term);
	return (0);
}

int	main(int argc, char **argv)
{
	t_gc		*head;
	t_context	*context;

	head = NULL;
	context = NULL;
	if (init_context(&context, argc, argv, &head))
		return (1);
	// TODO: do this cleaner
	gc_setenv("SHLVL", gc_itoa(ft_atoi(getenv("SHLVL")) + 1, &head), &head);
	init_sig(context->sa);
	if (init_environ(&head))
		return (1);
	set_input(&context);
	return (0);
}
