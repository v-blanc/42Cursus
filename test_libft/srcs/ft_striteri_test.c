/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/06 12:55:02 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

void	custom_tolower(unsigned int i, char *s)
{
	i = 0;
	if (*s >= 'A' && *s <= 'Z')
		*s = *s + 32;
}

void	custom_toupper(unsigned int i, char *s)
{
	i = 0;
	if (*s >= 'a' && *s <= 'z')
		*s = *s - 32;
}

int	main(void)
{
	char	s1[] = "HeLlO";

	printf("%s\n", s1);
	ft_striteri(s1, custom_tolower);
	printf("%s\n", s1);
	ft_striteri(s1, custom_toupper);
	printf("%s\n", s1);
}
