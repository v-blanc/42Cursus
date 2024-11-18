/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:33:31 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/18 15:00:15 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sub_atoi(const char *str, int *i, int *sign)
{
	while (ft_isspace(str[(*i)]))
		(*i)++;
	if (str[(*i)] == '-' || str[(*i)] == '+')
	{
		if (str[(*i)++] == '-')
			(*sign) = -1;
	}
}

/* Converts the initial portion of the string pointed to by ’str’ to int. */
int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;
	long	prev;

	i = 0;
	sign = 1;
	res = 0;
	ft_sub_atoi(str, &i, &sign);
	while (ft_isdigit(str[i]))
	{
		prev = res;
		res = res * 10 + (str[i++] - '0');
		if (res < prev)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
	}
	return ((int)res * sign);
}
