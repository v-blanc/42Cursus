/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:41:54 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/11 13:50:15 by vblanc           ###   ########.fr       */
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
	while (i <= ft_strlen(s) + 1)
		free(tab[i++]);
	return (tab);
}

#include <stdio.h>

int	main(void)
{
	char	**tab;
	int		i;

	tab = ft_split(" hello  world ", ' ');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}
