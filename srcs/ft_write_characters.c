/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:58:53 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/16 09:08:33 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_write_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_write_str(char *str)
{
	size_t	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = strlen(str);
	write(1, str, len);
	return ((int)len);
}

int	ft_write_ptr(size_t ptr)
{
	size_t	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = ft_write_hex(ptr, "0123456789abcdef");
	return (len + 2);
}
