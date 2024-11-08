/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/07 16:53:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

//TODO finish test
int	main(void)
{
	char	first[] = "Hello";
	char	last[] = "World";
	char	buffer[10];

	printf("%ld -> ", ft_strlcat(buffer, first, 10));
	printf("%s\n", buffer);
	printf("%ld -> ", ft_strlcat(buffer, last, 4));
	printf("%s\n", buffer);
	printf("%ld -> ", ft_strlcat(buffer, last, -1));
	printf("%s\n", buffer);
}
