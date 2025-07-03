/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:12:12 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/24 01:14:10 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_parse_format(char *str, va_list args)
{
	if (*str == 'c')
		return (ft_write_char(va_arg(args, int)));
	else if (*str == 's')
		return (ft_write_str(va_arg(args, char *)));
	else if (*str == 'p')
		return (ft_write_ptr(va_arg(args, void *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_write_decimal(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_write_unsigned(va_arg(args, size_t)));
	else if (*str == 'x')
		return (ft_write_hex(va_arg(args, int), "0123456789abcdef"));
	else if (*str == 'X')
		return (ft_write_hex(va_arg(args, int), "0123456789ABCDEF"));
	else if (*str == '%')
		return (write(1, "%", 1));
	else
		return (1);
	return (0);
}

int	ft_parse(char *str, va_list args)
{
	int	count_chars;

	count_chars = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count_chars += ft_parse_format(str, args);
			str++;
		}
		else
		{
			write(1, str, 1);
			count_chars++;
			str++;
		}
	}
	return (count_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*cpy;
	int		count_chars;

	if (!format)
		return (0);
	cpy = (char *)format;
	count_chars = 0;
	va_start(args, format);
	count_chars = ft_parse(cpy, args);
	va_end(args);
	return (count_chars);
}
