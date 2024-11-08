/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:15:11 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/07 17:57:19 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Locates the first occurrence of the null-terminated string ’little’ in
the string ’big’, where not more than ’len’ characters are searched.
Characters that appear after a ‘\0’ character are not searched. */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!big || !little)
		return (NULL);
	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (*big && i + ft_strlen(little) <= len)
	{
		if (ft_strncmp(big, little, 0) == 0)
			return ((char *)big);
		big++;
		i++;
	}
	// if (!*big || !len || (ft_strlen(little) + len > ft_strlen(big)))
	return (NULL);
	// return ((char *)big);
}
