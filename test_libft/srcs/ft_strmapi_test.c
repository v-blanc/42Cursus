/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/07 12:38:12 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

char	custom_tolower(unsigned int i, char c)
{
	i = 0;
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
    return (c);
}

char	custom_toupper(unsigned int i, char c)
{
	i = 0;
	if (c >= 'a' && c <= 'z')
		c = c - 32;
    return (c);
}

int	main(void)
{
    char	*str;

    str = "Hello World !";
    printf("%s\n", str);
    printf("%s\n", ft_strmapi(str, custom_tolower));
    printf("%s\n", ft_strmapi(str, custom_toupper));
}
