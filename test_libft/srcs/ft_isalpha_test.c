/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:51:10 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/14 15:52:58 by vblanc           ###   ########.fr       */
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
				ft_isalpha(i) ? "is alpha" : "is not alpha");
		else
			printf("(%d)\t’.%x’ %s\n", i, i,
				ft_isalpha(i) ? "is alpha" : "is not alpha");
		i++;
	}
}
