/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/07 17:17:11 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;

	str = "Hello World !";
	printf("%s\n", ft_strnstr(str, "World", 6));
	printf("%s\n", ft_strnstr(str, "World", 7));
	printf("%s\n", ft_strnstr(str, "World", 0));
	printf("%s\n", ft_strnstr(str, "#", 14));
	printf("%s\n", ft_strnstr(str, "", 10));
	printf("%s\n", ft_strnstr(str, "", 0));
	printf("%s\n", ft_strnstr("", "", 10));
	printf("%s\n", ft_strnstr("", "", 0));
	printf("%s\n", ft_strnstr(str, " !", 12));
}
