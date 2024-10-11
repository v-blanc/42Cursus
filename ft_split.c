/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:41:54 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/11 23:09:04 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*new_s;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		new_s = (char *)s;
		while (*new_s && *new_s != c)
			new_s++;
		if (new_s - s > 0)
			tab[i++] = ft_substr(s, 0, new_s - s);
		s = new_s + 1;
	}
	tab[i++] = NULL;
	return (tab);
}
