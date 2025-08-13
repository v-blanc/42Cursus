/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:20:22 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 12:47:58 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_functions.h"

extern char	**environ;

static int	update_environ(char **to_update, char *name, char *value,
		t_gc **head)
{
	(*to_update) = gc_malloc_perm(ft_strlen(name) + ft_strlen(value) + 2, head);
	if (!(*to_update))
		return (1);
	ft_strlcpy((*to_update), name, ft_strlen(name) + 1);
	if (value && value[0] != '\0')
		ft_strlcat((*to_update), "=", ft_strlen((*to_update)) + 2);
	ft_strlcat((*to_update), value, ft_strlen((*to_update)) + ft_strlen(value)
		+ 1);
	return (0);
}

static int	add_to_environ(int i, char *name, char *value, t_gc **head)
{
	char	**env_cpy;

	env_cpy = (char **)gc_malloc_array_perm(i + 1, head);
	if (!env_cpy)
		return (1);
	i = 0;
	while (environ[i])
	{
		env_cpy[i] = gc_malloc_perm(ft_strlen(environ[i]) + 1, head);
		if (!env_cpy[i])
			return (1);
		ft_strlcpy(env_cpy[i], environ[i], ft_strlen(environ[i]) + 1);
		i++;
	}
	if (update_environ(&env_cpy[i], name, value, head))
		return (1);
	environ = env_cpy;
	return (0);
}

int	gc_setenv(char *name, char *value, t_gc **head)
{
	int		i;
	char	last_char;

	if (name == NULL || value == NULL)
		return (1);
	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], name, ft_strlen(name)))
		{
			last_char = environ[i][ft_strlen(name)];
			if (last_char == '\0' || last_char == '=')
			{
				if (update_environ(&environ[i], name, value, head))
					return (1);
				return (0);
			}
		}
		i++;
	}
	if (add_to_environ(i, name, value, head))
		return (1);
	return (0);
}
