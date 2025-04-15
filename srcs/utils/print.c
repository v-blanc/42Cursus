#include "minishell.h"

static int	print_s(int fd, const char *s)
{
	size_t	characters_in_string;
	size_t	characters_printed;

	if (!s)
	{
		characters_printed = write(fd, "(null)", 6);
		return (characters_printed);
	}
	characters_in_string = 0;
	while (s[characters_in_string])
		characters_in_string++;
	characters_printed = write(fd, s, characters_in_string);
	return (characters_printed);
}

static short	print_d(int fd, int n)
{
	short			characters_printed;
	short			i;
	char			buffer[12];
	unsigned int	abs_n;
	const bool		negative = (n < 0);

	i = 12;
	buffer[i] = '\0';
	characters_printed = 0;
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
	characters_printed += write(fd, &buffer[i], 12 - i);
	return (characters_printed);
}

int	print(int fd, const char *format, ...)
{
	va_list	arguments;
	int		characters_printed;

	if (!format)
		return (-1);
	va_start(arguments, format);
	characters_printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				characters_printed += print_s(fd, va_arg(arguments, char *));
			else if (*format == 'd')
				characters_printed += print_d(fd, va_arg(arguments, int));
			format++;
		}
		else
			format += write(fd, format, 1);
	}
	va_end(arguments);
	return (characters_printed);
}
