/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 03:14:00 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/08 13:35:09 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a pointer to the first occurrence of the character ’c’
in the string ’s’. */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == (unsigned char)c)
			return ((char *)--s);
	}
	if (c % 256 == 0)
		return ((char *)s);
	return (NULL);
}
