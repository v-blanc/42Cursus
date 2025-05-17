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

int	repeat(t_ast *ast, t_context **ctx)

{
	char	**args;
	int		repeat;
	int		i;
	int		last_exit_status;

	args = ast->u_data.s_cmd.args + 1;
	if (args[0] == NULL || args[1] == NULL)
	{
		print(2, "minishell: repeat: missing operand\n");
		return (EXIT_FAILURE);
	}
	ast->u_data.s_cmd.args += 2;
	repeat = ft_atoi(args[0]);
	if (repeat <= 0)
	{
		print(2, "minishell: repeat: non-strictly positive '%s`\n", args[0]);
		return (EXIT_FAILURE);
	}
	i = -1;
	last_exit_status = 0;
	while (++i < repeat)
		last_exit_status = execute_ast(ast, *ctx);
	return (last_exit_status);
}
