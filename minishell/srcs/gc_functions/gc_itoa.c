/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:20:04 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 12:47:47 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_functions.h"

char	*gc_itoa(int n, t_gc **head)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (gc_strdup("-2147483648", head));
	str = gc_malloc(sizeof(char) * ft_intlen(n) + 1, head);
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
