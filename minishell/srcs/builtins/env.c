/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:33:43 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/18 14:26:46 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "exec.h"

extern char	**environ;

int	env(t_ast *ast, t_context **context)
{
	size_t	i;
	int		j;

	if (!environ || !*environ || !ast || !context || !*context)
		return (EXIT_FAILURE);
	i = 0;
	while (*ast->u_data.s_cmd.args && ft_strcmp(*ast->u_data.s_cmd.args,
			"env") == 0)
		ast->u_data.s_cmd.args++;
	if (*ast->u_data.s_cmd.args)
		return (execute_ast(ast, *context));
	else
	{
		i = 0;
		while (environ[i])
		{
			j = 0;
			while (environ[i][j] && environ[i][j] != '=')
				j++;
			if (environ[i][j] == '=')
				print(1, "%s\n", environ[i]);
			i++;
		}
		return (EXIT_SUCCESS);
	}
}
