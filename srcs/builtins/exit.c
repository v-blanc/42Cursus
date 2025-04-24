/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:33:46 by yabokhar          #+#    #+#             */
/*   Updated: 2025/04/24 19:03:52 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!isdigit(arg[i++]))
			return (0);
	}
	if ((int)ft_strlen(arg) > 20)
		return (0);
	if (arg[0] == '-' && (int)ft_strlen(arg) == 20)
	{
		if (ft_strncmp(arg, "-9223372036854775808", 21) > 0)
			return (0);
	}
	else if ((int)ft_strlen(arg) == 19)
	{
		if (ft_strncmp(arg, "9223372036854775807", 20) > 0)
			return (0);
	}
	return (1);
}

int	exit_(int args_count, char **args, t_context **context)
{
	int	exit_status;

	exit_status = 0;
	print(1, "exit\n");
	if (args_count == 2)
	{
		if (!is_valid_arg(args[0]))
		{
			print(2, "exit: %s: numeric argument required\n", args[0]);
			(*context)->last_exit_status = 2;
			exit(2);
		}
		exit_status = ft_atoi(args[0]);
		exit_status %= 256;
	}
	else if (args_count > 2)
	{
		print(2, "exit: too many arguments\n");
		(*context)->last_exit_status = 1;
		return (0);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &(*context)->orig_term);
	gc_free_all_perm(*((*context)->head));
	rl_clear_history();
	exit(exit_status);
	return (0);
}
