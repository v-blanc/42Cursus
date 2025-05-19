/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:34:07 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/19 15:30:35 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "exec.h"

extern char	**environ;

static int	to_unset_found(char **to_unset)
{
	int		i;
	int		found;
	int		j;
	char	last_char;

	found = 0;
	i = 0;
	while (to_unset[i])
	{
		j = 0;
		while (environ[j])
		{
			if (!ft_strncmp(environ[j], to_unset[i], ft_strlen(to_unset[i])))
			{
				last_char = environ[j][ft_strlen(to_unset[i])];
				if (last_char == '\0' || last_char == '=')
					found++;
			}
			j++;
		}
		i++;
	}
	return (found);
}

static int	sub_unset_env(char **to_unset, int *i, int *k)
{
	char	last_char;

	if (!ft_strncmp(environ[*i], to_unset[*k], ft_strlen(to_unset[*k])))
	{
		last_char = environ[*i][ft_strlen(to_unset[*k])];
		if (last_char == '\0' || last_char == '=')
		{
			(*i)++;
			*k = 0;
			return (1);
		}
	}
	return (0);
}

static int	unset_env(char ***new_env, char **to_unset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (environ[i])
	{
		k = 0;
		while (environ[i] && to_unset[k])
		{
			if (sub_unset_env(to_unset, &i, &k))
				continue ;
			k++;
		}
		if (environ[i])
			(*new_env)[j++] = environ[i++];
	}
	return (0);
}

int	unset(char **to_unset, t_gc **head)
{
	char	**new_env;
	int		new_env_size;

	if (to_unset == NULL || to_unset[0] == NULL)
		return (0);
	if (to_unset_found(to_unset) == 0)
		return (0);
	new_env_size = ft_strlen_array(environ) - to_unset_found(to_unset);
	new_env = (char **)gc_malloc_array_perm(new_env_size + 1, head);
	if (!new_env)
		return (1);
	if (unset_env(&new_env, to_unset))
		return (1);
	environ = new_env;
	return (0);
}
