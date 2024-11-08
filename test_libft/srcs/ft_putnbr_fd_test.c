/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/05 14:34:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    int fd = 1;

    ft_putnbr_fd(42, fd);
    printf("\n");
    ft_putnbr_fd(-2147483648, fd);
    printf("\n");
    ft_putnbr_fd(0, fd);
    printf("\n");
    ft_putnbr_fd(2147483647, fd);
    printf("\n");
}
