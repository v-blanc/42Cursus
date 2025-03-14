/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:15:11 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/08 14:53:04 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Locates the first occurrence of the null-terminated string ’little’ in
the string ’big’, where not more than ’len’ characters are searched.
Characters that appear after a ‘\0’ character are not searched. */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	if (!*little)
		return ((char *)big);
	i = 0;
	len_little = ft_strlen(little);
	while (big[i] && i + len_little <= len)
	{
		if (ft_strncmp(&big[i], little, len_little) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
