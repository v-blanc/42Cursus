/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:44:37 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/16 09:08:39 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_write_decimal(int num)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (num == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		len += write(1, "-", 1);
		num = -num;
	}
	if (num > 9)
	{
		len += ft_write_decimal(num / 10);
		len += write(1, &base[num % 10], 1);
	}
	else
		len += write(1, &base[num], 1);
	return (len);
}

int	ft_write_unsigned(unsigned int num)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (num > 9)
	{
		len += ft_write_unsigned(num / 10);
		len += write(1, &base[num % 10], 1);
	}
	else
		len += write(1, &base[num], 1);
	return (len);
}

int	ft_write_hex(unsigned int num, char *base)
{
	int	len;

	len = 0;
	if (num > 15)
	{
		len += ft_write_hex(num / 16, base);
		len += write(1, &base[num % 16], 1);
	}
	else
		len += write(1, &base[num], 1);
	return (len);
}
