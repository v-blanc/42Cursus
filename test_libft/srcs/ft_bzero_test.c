/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 06:07:24 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/14 07:04:13 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>

void	print_result(char *s, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		if (s[i] == '\0')
			printf(".");
		else
			printf("+");
		i++;
	}
	printf("\n");
}

int	main(void)
{
	char	s1[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
			'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char	s2[20] = "";
	char	s3[20];

	ft_bzero(s1, 0);
	print_result(s1, 20);
	ft_bzero(s1, 5);
	print_result(s1, 20);
	ft_bzero(s1, 20);
	print_result(s1, 20);
	ft_bzero(s2, 20);
	print_result(s2, 20);
	ft_bzero(s3, 20);
	print_result(s3, 20);
}
