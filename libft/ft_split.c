/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:41:54 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/18 15:23:49 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_sub_split(char const *s, char c, char **tab, int *i)
{
	char	*new_s;

	while (*s)
	{
		new_s = (char *)s;
		while (*new_s && *new_s != c)
			new_s++;
		if (new_s - s > 0)
		{
			tab[(*i)++] = ft_substr(s, 0, new_s - s);
			if (tab[(*i) - 1] == NULL)
			{
				while ((*i) > 0)
					free(tab[--(*i)]);
				free(tab);
				return (0);
			}
		}
		if (!*new_s)
			break ;
		s = new_s + 1;
	}
	tab[(*i)] = NULL;
	return (1);
}

/* Allocates (with malloc(3)) and returns an array of strings obtained
by splitting ’s’ using the character ’c’ as a delimiter.
The array is NULL-terminated. */
char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	if (!ft_sub_split(s, c, tab, &i))
		return (NULL);
	return (tab);
}
