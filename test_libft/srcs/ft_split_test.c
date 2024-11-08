/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/06 12:28:05 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

void	print_result(char *str, int c)
{
	char	**tab;
	int		i;

	tab = ft_split(str, c);
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
    printf(">%d\n", i);
    return ;
}

int	main(void)
{
	print_result("", '@');
	print_result("@", '@');
	print_result("@@@@@@", '@');
	print_result("@@Hello@World@@@!@42@@", '@');
	print_result("hello", '@');
}
