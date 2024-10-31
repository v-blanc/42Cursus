/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:53:33 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/31 13:21:23 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	i;

	i = 0;
	while (i <= 255)
	{
		if (isprint(i))
			printf("(%d)\t'%c' %s\n", i, i,
				ft_isascii(i) ? "is ascii" : "is not ascii");
		else
			printf("(%d)\t'.%x' %s\n", i, i,
				ft_isascii(i) ? "is ascii" : "is not ascii");
		i++;
	}
}
