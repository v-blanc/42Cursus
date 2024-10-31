/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:32:44 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/31 12:58:40 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies no more than ’n’ bytes from memory area ’src’ 
to memory area ’dest’, stopping when the character ’c’ is found.
If the memory areas overlap, the results are undefined. */
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n-- > 0)
	{
		if (*s == (unsigned char)c)
		{
			*d = *s;
			return ((void *)(d + 1));
		}
		*d++ = *s++;
	}
	return (NULL);
}
