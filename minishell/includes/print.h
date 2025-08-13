/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:54:30 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 13:03:44 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void	print(int fd, const char *format, ...);

#endif
