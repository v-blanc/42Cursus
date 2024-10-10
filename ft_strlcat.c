/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:55:53 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/10 03:12:42 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && (i + dst_len < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	while (i < size)
		dst[dst_len + i++] = '\0';
	if (size <= dst_len)
		return (src_len + size);
	return (src_len + dst_len);
}
