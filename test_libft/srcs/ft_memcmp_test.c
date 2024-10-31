/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:32:15 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/31 13:53:07 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s1 = "Hello";
	char *s2 = "HelloHello";
	char *s3 = "World";

	printf("%d\n", ft_memcmp(s1, s1, 5));
	printf("%d\n", ft_memcmp(s1, s3, 5));
	printf("%d\n", ft_memcmp(s1, s2, 5));
	printf("%d\n", ft_memcmp(s1, s2, 6));
	printf("%d\n", ft_memcmp(s1, s2, 10));
}
