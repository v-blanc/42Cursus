/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:49:58 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/15 18:26:06 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins_manager(t_ast *ast, t_context **context)
{
	int		args_count;
	char	**args;
	int		return_value;
	int		fd;

	fd = 1;
	return_value = 1;
	args_count = ast->u_data.s_cmd.args_count;
	args = ast->u_data.s_cmd.args;
	if (!ft_strncmp(args[0], "cd", 3))
		return_value = cd(fd, args_count, args + 1, (*context)->head);
	if (!ft_strncmp(args[0], "echo", 5))
		return_value = echo(fd, args + 1);
	if (!ft_strncmp(args[0], "env", 4))
		return_value = env(ast, context);
	if (!ft_strncmp(args[0], "exit", 5))
		return_value = exit_(args_count, args + 1, context);
	if (!ft_strncmp(args[0], "export", 8))
		return_value = export(fd, args_count, args + 1, (*context)->head);
	if (!ft_strncmp(args[0], "pwd", 4))
		return_value = pwd(fd);
	if (!ft_strncmp(args[0], "unset", 6))
		return_value = unset(args + 1, (*context)->head);
	(*context)->last_exit_status = return_value; // TODO: delete
	return (return_value);
}

void	exec_manager(t_ast *ast, t_context **context)
{
	if (ast->type == NODE_CMD)
	{
		if (is_builtin(ast->u_data.s_cmd.args[0]))
			builtins_manager(ast, context);
		else
			print(2, "Not builtins command: not working yet\n");
	}
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
