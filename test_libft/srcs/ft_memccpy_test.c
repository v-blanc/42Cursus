/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:49:18 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/31 13:12:52 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

void	print_result(char c, size_t n)
{
	const char	src[] = "1234567890";
	char		dest[10];
	char		*res;

	bzero(dest, 10);
	res = ft_memccpy(dest, src, c, n);
	if (res != NULL)
		res[0] = '\0';
	if (res == NULL)
		printf("’%c’ not found in the first ’%ld’ bytes of ’%s’\n", c, n, src);
	else
	{
		printf("’%c’ found in the first ’%ld’ bytes of ’%s’", c, n, src);
		printf(" | (address: %s) ", &res[0]
			- &dest[strlen(dest)] ? "unexpected" : "expected");
		printf("dest=%s\n", dest);
	}
}

int	main(void)
{
	print_result('0', 10);
	print_result('5', 10);
	print_result('5', 5);
	print_result('5', 4);
	print_result('5', 0);
	print_result('a', 10);
}