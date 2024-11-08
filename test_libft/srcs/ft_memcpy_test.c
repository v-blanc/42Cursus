/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:32:15 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/05 14:16:22 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "Hello";
	char s2[] = "..........";
	char s3[] = "World";

	ft_memcpy(s1 + 5, s1, strlen(s1));
	printf("%s\n", s1);
	ft_memcpy(s2, s3, 5);
	printf("%s\n", s2);
	ft_memcpy(s2, s3, 10);
	printf("%s\n", s2);
	ft_memcpy(s2, s1, 1);
	printf("%s\n", s2);
	ft_memcpy(s2, s3, 0);
	printf("%s\n", s2);
}
