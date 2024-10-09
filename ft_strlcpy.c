/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <temp@temp.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:04:45 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/09 21:30:37 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	end;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	end = 0;
	while (dst[end])
		end++;
	i = 0;
	while (src[i] && (i + end < size - 1))
	{
		dst[end + i] = src[i];
		i++;
	}
	while (i < size)
		dst[end + i++] = '\0';
	if (size <= dst_len)
		return (src_len + size);
	return (src_len + dst_len);
}
