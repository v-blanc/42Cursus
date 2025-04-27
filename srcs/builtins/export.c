/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:33:51 by yabokhar          #+#    #+#             */
/*   Updated: 2025/04/27 20:15:51 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

static void	sort_environ_indexes(int *environ_indexes)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (environ[i])
	{
		j = i + 1;
		while (environ[j])
		{
			if (ft_strncmp(environ[environ_indexes[i]],
					environ[environ_indexes[j]], ft_strlen(environ[i])) > 0)
			{
				tmp = environ_indexes[i];
				environ_indexes[i] = environ_indexes[j];
				environ_indexes[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	get_environ_sorted_indexes(int **environ_indexes, t_gc **head)
{
	int	i;
	int	len_environ;

	len_environ = ft_strlen_array(environ);
	(*environ_indexes) = (int *)gc_malloc(sizeof(int) * len_environ, head);
	if (!(*environ_indexes))
		return (1);
	i = -1;
	while (environ[++i])
		(*environ_indexes)[i] = i;
	sort_environ_indexes(*environ_indexes);
	return (0);
}

static int	print_export(int fd, t_gc **head)
{
	int	*env_ind;
	int	i;

	env_ind = NULL;
	if (get_environ_sorted_indexes(&env_ind, head))
		return (1);
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[env_ind[i]], "_=", 2) != 0)
			print(fd, "%s\n", environ[env_ind[i]]);
		i++;
	}
	gc_free(env_ind, head);
	return (0);
}

static int	export_one_var(char *arg, t_gc **head)
{
	char	*name;
	char	*value;
	int		i;

	name = NULL;
	value = "";
	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] && i == 0)
	{
		print(2, "export: %s: not a valid identifier\n", arg);
		return (0);
	}
	name = gc_strndup(arg, i, head);
	if (!name)
		return (1);
	if (arg[i] && arg[i + 1])
		value = gc_strdup(&arg[i + 1], head);
	if (!value)
		return (1);
	if (gc_setenv(name, value, head))
		return (1);
	return (0);
}

int	export(int fd, int args_count, char **args, t_gc **head)
{
	int	i;
	int	exit_status;

	exit_status = 0;
	if (args_count == 1)
	{
		if (print_export(fd, head))
			return (1);
	}
	else
	{
		i = 0;
		while (args[i])
		{
			if (!is_valid_export(args[i]))
			{
				print(2, "export: `%s`: not a valid identifier\n", args[i]);
				exit_status = 1;
			}
			else if (export_one_var(args[i], head))
				return (1);
			i++;
		}
	}
	return (exit_status);
}
