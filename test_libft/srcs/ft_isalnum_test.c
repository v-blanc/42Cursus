/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:38:10 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/31 13:17:58 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	i;

	i = 0;
	while (i <= 255)
	{
		if (isprint(i))
			printf("(%d)\t'%c' %s\n", i, i,
				ft_isalnum(i) ? "is alpha num" : "is not alpha num");
		else
			printf("(%d)\t'.%x' %s\n", i, i,
				ft_isalnum(i) ? "is alpha num" : "is not alpha num");
		i++;
	}
}
