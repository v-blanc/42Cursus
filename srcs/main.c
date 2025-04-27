/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:46:57 by yabokhar          #+#    #+#             */
/*   Updated: 2025/04/27 18:16:26 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	refresh_and_close(const int *temp_stdin, const int *temp_stdout)
{
	dup2(*temp_stdin, STDIN_FILENO);
	dup2(*temp_stdout, STDOUT_FILENO);
	close(*temp_stdin);
	close(*temp_stdout);
}

void	set_input(t_context **ctx)
{
	const int	temp_stdin = dup(STDIN_FILENO);
	const int	temp_stdout = dup(STDOUT_FILENO);
	t_ast		*ast;
	char		*input;
	char		*rl_prompt;

	while (1)
	{
		refresh_and_close(&temp_stdin, &temp_stdout);
		rl_prompt = set_readline_prompt(*ctx);
		if (rl_prompt == NULL)
		{
			gc_free_all((*ctx)->head);
			continue ;
		}
		input = readline(rl_prompt);
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
		if (execute_ast(ast, *ctx))
		{
			refresh_and_close(&temp_stdin, &temp_stdout);
			gc_free_all((*ctx)->head);
			continue ;
		}
		refresh_and_close(&temp_stdin, &temp_stdout);
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
			print(2, "env error\n"); // TODO: update
			return (1);
		}
		environ[0] = gc_strjoin_perm("PWD=", env_pwd, head);
		environ[1] = gc_strjoin_perm("SHLVL=1", "", head);
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
	(*context)->argc = argc;
	(*context)->argv = argv;
	(*context)->last_exit_status = 0;
	(*context)->head = head;
	(*context)->orig_term = (struct termios){0};
	tcgetattr(STDIN_FILENO, &(*context)->orig_term);
	return (0);
}

int	main(int argc, char **argv)
{
	t_gc		*head;
	t_context	*context;

	if (argc > 1) // TODO: rework to allow multiple arguments ?
		return (1);
	head = NULL;
	context = NULL;
	if (init_context(&context, argc, argv, &head))
		return (1);
	init_sig();
	if (init_environ(&head))
		return (1);
	set_input(&context);
	return (0);
}
