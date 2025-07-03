/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:53:06 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/21 00:56:20 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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
