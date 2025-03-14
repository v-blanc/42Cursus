/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:18:28 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/08 12:57:32 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/* Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers are handled. */
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
