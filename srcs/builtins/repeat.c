/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:41:52 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/16 23:12:17 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			repeat(t_ast *ast, t_context **ctx);
static char *join_args(char **args, t_gc **head);

int	repeat(t_ast *ast, t_context **ctx)

{
	char	**args;
	char	*command;
	int		repeat_count;
	int		i;
	t_ast	*node;

	args = ast->u_data.s_cmd.args + 1;
	if (!args[0] || !args[1])
	{
		print(2, "minishell: repeat: missing operand\n");
		return (EXIT_FAILURE);
	}
	repeat_count = ft_atoi(args[0]);
	if (repeat_count <= 0)
	{
		print(2, "minishell: repeat: non-strictly positive count '%s`\n", args[0]);
		return (EXIT_FAILURE);
	}
	command = join_args(args + 1, (*ctx)->head);
	node = NULL;
	if (!command || parsing(command, &node, ctx))
	{
		gc_free(command, (*ctx)->head);
		return (EXIT_FAILURE);
	}
	gc_free(command, (*ctx)->head);
	i = -1;
	while (++i < repeat_count)
		execute_ast(node, *ctx);
	return ((*ctx)->last_exit_status);
}

static char	*join_args(char **args, t_gc **head)

{
	char	*result;
	char	*temp;
	int		i;

	if (!args || !*args)
		return (NULL);
	result = gc_strdup("", head);
	i = -1;
	while (args[++i])
	{
		temp = gc_strjoin(result, " ", head);
		gc_free(result, head);
		result = temp;
		temp = gc_strjoin(result, args[i], head);
		gc_free(result, head);
		result = temp;
	}
	return (result);
}
