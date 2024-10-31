/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:18:28 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/21 22:25:08 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers are handled. */
char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign_flag;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		sign_flag = 1;
		n = -n;
	}
	while (n > 9)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	str[i] = n + '0';
	if (sign_flag == 1)
		str[++i] = '-';
	ft_strrev(str);
	return (str);
}
