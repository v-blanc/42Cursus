/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:49:19 by yabokhar          #+#    #+#             */
/*   Updated: 2025/05/15 20:28:11 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print(int fd, const char *format, ...);
static void	print_string(int fd, const char *s);
static void	print_number(int fd, const int n);

void	print(int fd, const char *format, ...)
{
	va_list	arguments;

	if (!format)
		return ;
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				print_string(fd, va_arg(arguments, char *));
			else if (*format == 'd')
				print_number(fd, va_arg(arguments, int));
		}
		else
			write(fd, format, 1);
		format++;
	}
	va_end(arguments);
}
static void	print_string(int fd, const char *s)
{
	size_t	characters_in_string;

	if (!s)
	{
		write(fd, "(null)", 6);
		return ;
	}
	characters_in_string = 0;
	while (s[characters_in_string])
		characters_in_string++;
	write(fd, s, characters_in_string);
}

static void	print_number(int fd, const int n)
{
	short				i;
	char				buffer[12];
	unsigned int		abs_n;
	const bool			negative = (n < 0);

	i = 11;
	buffer[i] = '\0';
	if (n == 0)
		buffer[--i] = '0';
	abs_n = ft_abs(n);
	while (abs_n > 0)
	{
		buffer[--i] = (abs_n % 10) + '0';
		abs_n /= 10;
	}
	if (negative)
		buffer[--i] = '-';
	write(fd, &buffer[i], 12 - i);
}
