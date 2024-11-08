/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/07 13:39:01 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower('z'));
	printf("%c\n", ft_tolower('Z'));
	printf("%c\n", ft_tolower('0'));
	printf("%c\n", ft_tolower('9'));
	printf("%c\n", ft_tolower(' '));
	printf("%c\n", ft_tolower('\n'));
	printf("%c\n", ft_tolower('4'));
	printf("%c\n", ft_tolower('2'));
}
