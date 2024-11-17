/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:12:12 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/16 09:08:25 by vblanc           ###   ########.fr       */
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
		return (ft_write_ptr(va_arg(args, size_t)));
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
/*
int	main(void)
{
	int		count;
	char	*test_str;
	int		test_number;
	char	test_char;

	test_char = 't';
	test_str = "test";
	test_number = 1234;
	printf("------- Testing %%c -------\n");
	count = ft_printf("%c|\n", test_char);
	printf("count: %d\n", count);
	printf("expected: ");
	count = printf("%c|\n", test_char);
	printf("expected count: %d\n", count);
	printf("------- Testing %%s -------\n");
	count = ft_printf("%s|\n", test_str);
	printf("count: %d\n", count);
	printf("expected: ");
	count = printf("%s|\n", test_str);
	printf("expected count: %d\n", count);
	printf("------- Testing %%p -------\n");
	count = ft_printf("%p|\n", test_str);
	printf("count: %d\n", count);
	printf("expected: ");
	count = printf("%p|\n", test_str);
	printf("expected count: %d\n", count);
	printf("------- Testing %%d -------\n");
	count = ft_printf("%d|\n", test_number);
	printf("count: %d\n", count);
	printf("expected: ");
	count = printf("%d|\n", test_number);
	printf("expected count: %d\n", count);
	printf("------- Testing %%x -------\n");
	count = ft_printf("%x|\n", test_number);
	printf("count: %d\n", count);
	printf("expected: ");
	count = printf("%x|\n", test_number);
	printf("expected count: %d\n", count);
	printf("------- Testing %%X -------\n");
	count = ft_printf("%X|\n", test_number);
	printf("count: %d\n", count);
	printf("expected: ");
	count = printf("%X|\n", test_number);
	printf("expected count: %d\n", count);
	printf("------- Testing %%%% -------\n");
	count = ft_printf("%%|\n");
	printf("count: %d\n", count);
	printf("expected: ");
	count = printf("%%|\n");
	printf("expected count: %d\n", count);
	return (0);
}
*/
