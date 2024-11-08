/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:06:09 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/07 14:02:52 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void	test_ft_calloc(size_t n, size_t size)
{
	char	*s;
	size_t	total;

	total = n * size;
	s = calloc(n, size);
	if (!s)
	{
		printf("calloc failed\n");
		return ;
	}
	while (total-- > 0)
	{
		if (s[n] == '\0')
			printf(".");
		else
			printf("+");
	}
	printf("\n");
	free(s);
}

void	test_ft_calloc_int(size_t n, size_t size)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_calloc(n, size);
	if (!s)
	{
		printf("calloc failed\n");
		return ;
	}
	s[3] = 1;
	s[n - 1] = 2;
	s[n] = 3;
	while (i < (int)n)
		printf("%d", s[i++]);
	printf("\n");
	free(s);
}

int	main(void)
{
	test_ft_calloc(10, 5);
	test_ft_calloc(0, 50);
	test_ft_calloc(50, 0);
	if(ft_calloc(INT_MAX, 1) == NULL)
		printf("calloc failed for INT_MAX\n");
	else
		printf("calloc passed for INT_MAX\n");
	if(ft_calloc(INT_MAX / 2 + 1, 2) == NULL)
		printf("calloc failed for INT_MAX + 1\n");
	else
		printf("calloc passed for INT_MAX + 1\n");
	test_ft_calloc_int(10, sizeof(int));
	test_ft_calloc_int(INT_MAX, sizeof(int));
	return (0);
}
