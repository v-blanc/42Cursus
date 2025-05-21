/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:21:50 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/21 17:02:00 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_input.h"

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

static void	get_pwd(char **pwd)
{
	char	*home_path;

	if (getcwd(*pwd, PATH_MAX) == NULL)
		print(2, "minishell: getcwd: %s\n", strerror(errno));
	if (*pwd)
	{
		home_path = getenv("HOME");
		if (home_path && !ft_strncmp(*pwd, home_path, ft_strlen(home_path)))
		{
			ft_strlcpy(*pwd, *pwd + ft_strlen(home_path) - 1, PATH_MAX);
			(*pwd)[0] = '~';
		}
	}
	else
		*pwd = "";
}

char	*set_readline_prompt(t_context *ctx)
{
	char	*pwd;
	char	*rl_prompt;

	pwd = gc_malloc(PATH_MAX, ctx->head);
	get_pwd(&pwd);
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

int	is_valid_rl_input(char *input, t_context **ctx)
{
	int	i;

	i = 0;
	if (!input)
		exit_eof(ctx);
	if (input[0] == '\n' || input[0] == '\0')
		return (0);
	while (input[i] && ft_isspace(input[i]))
		i++;
	if (input[i] == '\0' || input[i] == ':')
	{
		(*ctx)->last_exit_status = 0;
		return (0);
	}
	else if (input[0] == '!')
	{
		(*ctx)->last_exit_status = 1;
		return (0);
	}
	return (1);
}
