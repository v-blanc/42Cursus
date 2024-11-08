/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:32:15 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/07 15:10:03 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

void	print_result(char c, size_t n)
{
	const char	src[] = "0123456789";
	char		*res;

	res = ft_memchr(src, c, n);
	if (res == NULL)
		printf("'%c' not found in the first '%ld' bytes of '%s'\n", c, n, src);
	else
	{
		printf("'%c' found in the first '%ld' bytes of '%s'", c, n, src);
		printf("at index %ld\n", &res[0] - &src[0]);
	}
}

int	main(void)
{
	print_result('9', 10);
	print_result('5', 10);
	print_result('5', 6);
	print_result('5', 5);
	print_result('5', 0);
	print_result('a', 10);
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%s", (char *)ft_memchr(tab, -1, 7));
}
