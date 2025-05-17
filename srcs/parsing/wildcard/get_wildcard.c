/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wildcard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:37:58 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/17 20:09:27 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_files(char *cwd)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	count = 0;
	dir = opendir(cwd);
	if (!dir)
		return (0);
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (entry->d_name[0] == '.')
			continue ;
		if (entry->d_type != DT_UNKNOWN)
			count++;
	}
	if (closedir(dir))
		return (0);
	return (count);
}

static int	get_files(char **files, char *cwd, int count, t_gc **head)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(cwd);
	if (!dir)
		return (0);
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (entry->d_name[0] == '.')
			continue ;
		if (entry->d_type != DT_UNKNOWN)
		{
			files[count - 1] = gc_strdup(entry->d_name, head);
			if (!files[count - 1])
				return (closedir(dir));
			count--;
		}
	}
	return (closedir(dir));
}

static int	strcmp_wildcard(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (isupper(s1[i]) && islower(s2[i]))
		return ((unsigned char)s1[i] - (unsigned char)s2[i] + 32);
	else if (islower(s1[i]) && isupper(s2[i]))
		return ((unsigned char)s1[i] - (unsigned char)s2[i] - 32);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	sort_files(char **files, int count)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (strcmp_wildcard(files[i], files[j]) > 0)
			{
				tmp = files[i];
				files[i] = files[j];
				files[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_wildcard(char ***files, t_gc **head)
{
	char	*cwd;
	int		count;

	cwd = gc_malloc(PATH_MAX, head);
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		printf("minishell: getcwd: %s\n", strerror(errno));
		return (-1);
	}
	count = count_files(cwd);
	if (!count)
		return (0);
	(*files) = (char **)gc_malloc_array(count, head);
	if (!(*files))
		return (1);
	if (get_files(*files, cwd, count, head))
		return (1);
	sort_files(*files, count);
	return (0);
}
