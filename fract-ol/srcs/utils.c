/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:50:25 by vblanc            #+#    #+#             */
/*   Updated: 2025/03/13 10:20:19 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

double	sub_ft_atof(const char *str)
{
	double	result;
	double	decimal_place;

	result = 0.0;
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		decimal_place = 1.0;
		while (ft_isdigit(*str))
		{
			decimal_place *= 0.1;
			result += (*str - '0') * decimal_place;
			str++;
		}
	}
	return (result);
}

double	ft_atof(const char *str)
{
	int	sign;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (sign * sub_ft_atof(str));
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_dtoa_2f(double f)
{
	char	*str;
	char	*tmp_int;
	char	*tmp_float;
	int		i;
	int		j;

	str = ft_calloc(sizeof(char), 30);
	i = 0;
	if (f < 0)
		str[i++] = '-';
	tmp_int = ft_itoa(ft_abs((int)f));
	tmp_float = ft_itoa((int)ft_abs((f - (int)f) * 100));
	j = 0;
	while (tmp_int[j])
		str[i++] = tmp_int[j++];
	str[i++] = '.';
	if (ft_strlen(tmp_float) == 1)
		str[i++] = '0';
	j = 0;
	while (tmp_float[j])
		str[i++] = tmp_float[j++];
	free(tmp_int);
	free(tmp_float);
	return (str);
}
