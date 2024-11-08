/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/05 14:29:08 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    int fd = 1;

    ft_putchar_fd('a', fd);
    ft_putchar_fd('z', fd);
    ft_putchar_fd('\n', fd);
    ft_putchar_fd('4', fd);
    ft_putchar_fd('2', fd);
    ft_putchar_fd('\n', fd);
}
