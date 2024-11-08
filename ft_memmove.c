/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:40:04 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/05 13:15:59 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies ’n’ bytes from memory area ’src’ to memory area ’dest’.
The memory areas may overlap: copying takes place as though the bytes in ’src’
are first copied  into  a temporary  array  that does not overlap ’src’
or ’dest’, and the bytes are then copied from the temporary array to ’dest’. */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (s < d)
	{
		d += n - 1;
		s += n - 1;
		while (n-- > 0)
			*d-- = *s--;
	}
	else
		ft_memcpy(d, s, n);
	return (dest);
}
