/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:49:58 by yabokhar          #+#    #+#             */
/*   Updated: 2025/04/16 10:50:07 by yabokhar         ###   ########.fr       */
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
	args_count = ast->u_data.s_cmd.args_count;
	args = ast->u_data.s_cmd.args;
	if (!ft_strncmp(args[0], "cd", 3))
		return_value = cd(fd, args_count, args + 1, (*context)->head);
	if (!ft_strncmp(args[0], "echo", 5))
		return_value = echo(fd, args + 1);
	if (!ft_strncmp(args[0], "env", 4))
		return_value = env(fd, args_count);
	if (!ft_strncmp(args[0], "exit", 5))
		return_value = exit_(args_count, args + 1, context);
	if (!ft_strncmp(args[0], "export", 8))
		return_value = export(fd, args_count, args + 1, (*context)->head);
	if (!ft_strncmp(args[0], "pwd", 4))
		return_value = pwd(fd);
	if (!ft_strncmp(args[0], "unset", 6))
		return_value = unset(args + 1, (*context)->head);
	if (return_value)
		printf(">>> BUILTINS ERROR\n");
	return (return_value);
}

void	exec_manager(t_ast *ast, t_context **context)
{
	if (ast->type == NODE_CMD)
	{
		if (is_builtin(ast->u_data.s_cmd.args[0]))
			builtins_manager(ast, context);
		else
			printf("Not builtins command: not working yet\n");
	}
}
