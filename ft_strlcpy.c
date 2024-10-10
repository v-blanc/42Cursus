/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:04:45 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/10 03:06:02 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < size)
		dst[i++] = '\0';
	return (ft_strlen(src));
}
