/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:28:05 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/04 14:15:37 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Compares the first ’n’ bytes (each interpreted as unsigned char)
of the memory areas ’s1’ and ’s2’ and returns an integer less than, equal to,
or greater than zero if the first ’n’ bytes of ’s1’ is found, respectively,
to be less than, to match, or be greater than the first ’n’ bytes of ’s2’.*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	while (n-- > 0)
	{
		if (*ptr1++ != *ptr2++)
			return (*--ptr1 - *--ptr2);
	}
	return (0);
}
