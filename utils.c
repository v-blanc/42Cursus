/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:12:33 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/29 12:23:57 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (--i);
}

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}

static char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	len;

	len = ft_strlen(s) + 1;
	d = (char *)malloc(sizeof(char) * len);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len);
	return (d);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * ft_intlen(n) + 1);
	if (!str)
		return (NULL);
	i = ft_intlen(n);
	str[i--] = '\0';
	if (n < 0)
		str[0] = '-';
	n = ((n > 0) - (n < 0)) * n;
	while (n > 9)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	str[i] = n + '0';
	return (str);
}
