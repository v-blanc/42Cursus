/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:25:07 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 21:30:50 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
		env_pwd = gc_malloc(PATH_MAX, head);
		if (!env_pwd)
			return (1);
		if (getcwd(env_pwd, PATH_MAX) == NULL)
		{
			print(2, "minishell: env error\n");
			gc_free_all_perm(*head);
			return (1);
		}
		environ[0] = gc_strjoin_perm("PWD=", env_pwd, head);
		environ[1] = gc_strjoin_perm("SHLVL=0", "", head);
		environ[2] = gc_strjoin_perm("_=/usr/bin", "", head);
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
		return (EXIT_FAILURE);
	set_ptr(*context);
	(*context)->argc = argc;
	(*context)->argv = argv;
	(*context)->last_exit_status = 0;
	(*context)->last_node_type = -1;
	(*context)->head = head;
	(*context)->orig_term = (struct termios){0};
	(*context)->backup_fds[STDIN_FILENO] = dup(STDIN_FILENO);
	if (((*context)->backup_fds[STDIN_FILENO] < 0))
		return (EXIT_FAILURE);
	(*context)->backup_fds[STDOUT_FILENO] = dup(STDOUT_FILENO);
	if (((*context)->backup_fds[STDIN_FILENO] < 0))
		return (EXIT_FAILURE);
	(*context)->signal = 0;
	(*context)->is_in_heredoc = 0;
	tcgetattr(STDIN_FILENO, &(*context)->orig_term);
	return (EXIT_SUCCESS);
}

int	update_shlvl(t_gc **head)
{
	char	*shlvl;
	char	*shlvl_updated;

	shlvl = getenv("SHLVL");
	if (!shlvl)
	{
		print(2, "minishell: env error\n");
		return (1);
	}
	shlvl_updated = gc_itoa(ft_atoi(shlvl) + 1, head);
	if (!shlvl_updated)
		return (1);
	return (gc_setenv("SHLVL", shlvl_updated, head));
}
