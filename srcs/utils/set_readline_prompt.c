/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_readline_prompt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:21:50 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/27 19:24:58 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sub_set_readline_prompt(char **rl_prompt, t_context *ctx)
{
	if (ctx->last_exit_status == 0)
		*rl_prompt = gc_strjoin(GREEN "➜  " RESET, *rl_prompt, ctx->head);
	else
		*rl_prompt = gc_strjoin(RED "➜  " RESET, *rl_prompt, ctx->head);
	if (!rl_prompt)
		return (1);
	return (0);
}

char	*set_readline_prompt(t_context *ctx)
{
	char	*pwd;
	char	*home_path;
	char	*rl_prompt;

	pwd = getenv("PWD");
	if (!pwd)
		return (NULL);
	home_path = getenv("HOME");
	if (home_path && !ft_strncmp(pwd, home_path, ft_strlen(home_path)))
	{
		ft_strlcpy(pwd, pwd + ft_strlen(home_path) - 1, PATH_MAX);
		pwd[0] = '~';
	}
	rl_prompt = gc_strjoin(GREEN "minishell" RESET ":" BLUE, pwd, ctx->head);
	if (!rl_prompt)
		return (NULL);
	rl_prompt = gc_strjoin(rl_prompt, RESET "$ ", ctx->head);
	if (!rl_prompt)
		return (NULL);
	if (sub_set_readline_prompt(&rl_prompt, ctx))
		return (NULL);
	return (rl_prompt);
}
