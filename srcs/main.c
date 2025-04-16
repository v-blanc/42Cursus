/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:46:57 by yabokhar          #+#    #+#             */
/*   Updated: 2025/04/16 18:28:38 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*set_readline_prompt(t_gc **head)
{
	char	*rl_prompt;
	char	*final_rl_prompt;
	char	pwd[PATH_MAX];
	char	*pwd_home;

	ft_strlcpy(pwd, getenv("PWD"), PATH_MAX);
	pwd_home = getenv("HOME");
	if (pwd_home != NULL && !ft_strncmp(pwd, pwd_home, ft_strlen(pwd_home)))
	{
		ft_strlcpy(pwd, pwd + ft_strlen(pwd_home) - 1, PATH_MAX);
		pwd[0] = '~';
	}
	rl_prompt = gc_strjoin("minishell:", pwd, head);
	if (!rl_prompt)
		return (NULL);
	final_rl_prompt = gc_strjoin(rl_prompt, "$ ", head);
	if (!final_rl_prompt)
		return (NULL);
	gc_free(rl_prompt, head);
	return (final_rl_prompt);
}
// test
void	set_input(t_context **context, t_gc **head)
{
	const int	temp_stdin = dup(STDIN_FILENO);
	const int	temp_stdout = dup(STDOUT_FILENO);
	t_ast	*ast;
	char	*input;
	char	*rl_prompt;

	while (1)
	{
		dup2(temp_stdin, STDIN_FILENO);
		dup2(temp_stdout, STDOUT_FILENO);
		rl_prompt = set_readline_prompt(head);
		if (rl_prompt == NULL)
		{
			gc_free_all(head);
			//continue ;
		}
		input = readline(rl_prompt);
		if (!input)
		{
			print(2, "readline: %s\n", strerror(errno));
			gc_free_all(head);
		}
		ast = NULL;
		if (parsing(input, &ast, context, head))
		{
			free(input);
			gc_free_all(head);
			//continue ;
		}
		printf("\n******************************************\n");
		print_ast(ast, 0);
		printf("\n******************************************\n\n");
		if (execute_ast(ast, *context))
		{
			free(input);
			gc_free_all(head);
			continue ;
		}
		add_history(input);
		free(input);
		gc_free_all(head);
	}
}

extern char	**environ;

int	init_environ(t_gc **head)
{
	char	*env_pwd;

	env_pwd = NULL;
	if (environ == NULL || environ[0] == NULL)
	{
		environ = (char **)gc_malloc_array_perm(3, head);
		if (!environ)
			return (1);
		if (getcwd(env_pwd, PATH_MAX) == NULL)
		{
			print(2, "getcwd: %s\n", strerror(errno));
			return (1);
		}
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
	set_input(&context, &head);
	return (0);
}
