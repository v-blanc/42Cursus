/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/07 12:51:59 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "Hello";
	s2 = "HelloHello";
	s3 = "World";
	printf("%d\n", ft_strncmp(s1, s1, 5));
	printf("%d\n", ft_strncmp(s1, s1, 0));
	printf("%d\n", ft_strncmp(s1, s2, 5));
	printf("%d\n", ft_strncmp(s1, s2, 6));
	printf("%d\n", ft_strncmp(s1, s2, 10));
	printf("%d\n", ft_strncmp(s1, s3, 5));
	printf("%d\n", ft_strncmp("", s3, 10));
	printf("%d\n", ft_strncmp("", "", 10));
}
