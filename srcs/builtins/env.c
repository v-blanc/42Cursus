/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:33:43 by yabokhar          #+#    #+#             */
/*   Updated: 2025/04/18 18:34:48 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

/*static int	print_error(char *argument, int error, int status)

{
	print(2, "env: ‘%s’: %s", argument, strerror(error));
	return (status);
}*/

int	env(t_ast *ast, t_context **context)
{
	//struct stat	buffer;
	size_t		i;
	//char 		**arguments = ast->u_data.s_cmd.args;
	i = 0;
	while (*ast->u_data.s_cmd.args && ft_strcmp(*ast->u_data.s_cmd.args, "env") == 0)
		ast->u_data.s_cmd.args++;
	if (*ast->u_data.s_cmd.args)
		return (execute_ast(ast, *context));
	else
	{
		i = -1;
		while (environ[++i])
			print(1, "%s\n", environ[i]);
		return (EXIT_SUCCESS);
	}
}
