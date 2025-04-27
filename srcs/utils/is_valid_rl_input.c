/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_rl_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:21:45 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/27 19:22:16 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
