/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:19:57 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 12:48:17 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_functions.h"

char	*gc_strdup(const char *s, t_gc **head)
{
	char	*d;
	size_t	len;

	len = ft_strlen(s) + 1;
	d = (char *)gc_malloc(sizeof(char) * len, head);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len);
	return (d);
}

char	*gc_strdup_perm(const char *s, t_gc **head)
{
	char	*d;
	size_t	len;

	len = ft_strlen(s) + 1;
	d = (char *)gc_malloc_perm(sizeof(char) * len, head);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len);
	return (d);
}
