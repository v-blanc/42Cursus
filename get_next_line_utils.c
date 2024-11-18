/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:11:31 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/18 23:25:19 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (--i);
}

static void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = 0;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > 2147483647 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s++ == (unsigned char)c)
			return ((char *)--s);
		i++;
	}
	if (c % 256 == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_custom(char *s1, char *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = strlen(s1);
	s2_len = strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	memcpy(res, s1, s1_len);
	memcpy(res + s1_len, s2, s2_len);
	res[s1_len + s2_len] = '\0';
	free(s1);
	return (res);
}
