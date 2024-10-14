/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:09:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/14 16:30:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
}
