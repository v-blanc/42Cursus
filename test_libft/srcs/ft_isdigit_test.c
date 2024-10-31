/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:55:18 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/31 13:21:35 by vblanc           ###   ########.fr       */
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
				ft_isdigit(i) ? "is digit" : "is not digit");
		else
			printf("(%d)\t'.%x' %s\n", i, i,
				ft_isdigit(i) ? "is digit" : "is not digit");
		i++;
	}
}
