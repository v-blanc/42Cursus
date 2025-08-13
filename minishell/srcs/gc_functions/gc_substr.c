/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:20:17 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 12:48:49 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_functions.h"

char	*gc_substr(char const *s, unsigned int start, size_t len, t_gc **head)
{
	char	*sub;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (len_s - start < len)
		len = len_s - start;
	if (start > len_s)
		return (gc_strdup("", head));
	sub = (char *)gc_malloc(sizeof(char) * len + 1, head);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}
