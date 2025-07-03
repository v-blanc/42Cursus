/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:45:27 by vblanc            #+#    #+#             */
/*   Updated: 2024/12/13 12:08:33 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

/* ft_printf */

int	ft_printf(const char *format, ...);

/* ft_write_characters */

int	ft_write_char(int c);
int	ft_write_str(char *str);
int	ft_write_ptr(void *ptr);

/* ft_write_numbers */

int	ft_write_decimal(int num);
int	ft_write_unsigned(unsigned int num);
int	ft_write_hex(unsigned int num, char *base);

#endif
