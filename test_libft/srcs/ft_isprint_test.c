/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:05 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/14 15:58:32 by vblanc           ###   ########.fr       */
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
			printf("(%d)\t’%c’ %s\n", i, i,
				ft_isprint(i) ? "is print" : "is not print");
		else
			printf("(%d)\t’.%x’ %s\n", i, i,
				ft_isprint(i) ? "is print" : "is not print");
		i++;
	}
}
