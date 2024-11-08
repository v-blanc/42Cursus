/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/06 15:37:38 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

//TODO finish test
int	main(void)
{
	char	dest[20];

	printf("%ld -> ", ft_strlcpy(dest, "Hello", 10));
	printf("%s\n", dest);
	printf("%ld -> ", ft_strlcpy(dest, "World", 4));
	printf("%s\n", dest);
}
