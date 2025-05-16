/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:49:58 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/16 23:23:21 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins_manager(t_ast *ast, t_context **context)
{
	int		args_count;
	char	**args;

	args_count = ast->u_data.s_cmd.args_count;
	args = ast->u_data.s_cmd.args;
	if (!ft_strncmp(args[0], "cd", 3))
		return (cd(1, args_count, args + 1, (*context)->head));
	if (!ft_strncmp(args[0], "echo", 5))
		return (echo(1, args + 1));
	if (!ft_strncmp(args[0], "env", 4))
		return (env(ast, context));
	if (!ft_strncmp(args[0], "exit", 5))
		return (exit_(args_count, args + 1, context));
	if (!ft_strncmp(args[0], "export", 8))
		return (export(1, args_count, args + 1, (*context)->head));
	if (!ft_strncmp(args[0], "pwd", 4))
		return (pwd(1));
	if (!ft_strncmp(args[0], "unset", 6))
		return (unset(args + 1, (*context)->head));
	if (!ft_strncmp(args[0], "repeat", 6))
		return (repeat(ast, context));
	return (EXIT_FAILURE);
}

char	**get_input(t_context *ctx)

{
	size_t		i;
	size_t		length;
	static char	*input[2];

	write(1, "> ", 2);
	input[0] = get_next_line(STDIN_FILENO, ctx);
	i = 0;
	length = ft_strlen(input[0]);
	while (i < length)
	{
		if ((input[0][i] >= '\t' && input[0][i] <= '\r') || input[0][i] == ' ')
		{
			while (i < length)
			{
				input[0][i] = '\0';
				i++;
			}
		}
		i++;
	}
	input[1] = NULL;
	return (input);
}

bool	is_builtin(char *command)

{
	if (!command)
		return (false);
	if (!ft_strncmp(command, "cd", 3))
		return (true);
	if (!ft_strncmp(command, "echo", 5))
		return (true);
	if (!ft_strncmp(command, "env", 4))
		return (true);
	if (!ft_strncmp(command, "exit", 5))
		return (true);
	if (!ft_strncmp(command, "export", 8))
		return (true);
	if (!ft_strncmp(command, "pwd", 4))
		return (true);
	if (!ft_strncmp(command, "unset", 6))
		return (true);
	if (!ft_strncmp(command, "repeat", 6))
		return (true);
	return (false);
}
