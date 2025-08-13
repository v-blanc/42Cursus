/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:20:13 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 12:48:43 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_functions.h"

char	*gc_strndup(const char *s, size_t n, t_gc **head)
{
	size_t	i;
	char	*dup;

	dup = gc_malloc(n + 1, head);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
