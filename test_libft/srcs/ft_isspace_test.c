/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:01:56 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/31 13:19:32 by vblanc           ###   ########.fr       */
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
				ft_isspace(i) ? "is space" : "is not space");
		else
			printf("(%d)\t'.%x' %s\n", i, i,
				ft_isspace(i) ? "is space" : "is not space");
		i++;
	}
}
