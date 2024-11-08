/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:32:15 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/05 14:25:46 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "Hello";

	printf("%s\n", s1);
	printf("%s\n", (char *)ft_memset(s1, '.', 5));
	printf("%s\n", (char *)ft_memset(s1, '!', 6));
	printf("%s\n", (char *)ft_memset(s1, '.', 3));
	printf("%s\n", (char *)ft_memset(s1, '0', 6));
}
