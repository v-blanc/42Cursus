/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:58:53 by vblanc            #+#    #+#             */
/*   Updated: 2024/12/13 12:07:06 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_write_char(int c)
{
	write(1, &c, 1);
	return (1);
}

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_write_str(char *str)
{
	size_t	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	write(1, str, len);
	return ((int)len);
}

static int	ft_write_ull_hex(unsigned long long num, char *base)
{
	int	len;

	len = 0;
	if (num > 15)
	{
		len += ft_write_ull_hex(num / 16, base);
		len += write(1, &base[num % 16], 1);
	}
	else
		len += write(1, &base[num], 1);
	return (len);
}

int	ft_write_ptr(void *ptr)
{
	size_t	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = ft_write_ull_hex((unsigned long long)ptr, "0123456789abcdef");
	return (len + 2);
}
