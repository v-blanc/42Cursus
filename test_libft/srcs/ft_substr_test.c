/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/07 13:35:26 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;

	str = "Hello World !";
	printf("%s\n", ft_substr(str, 0, 5));
	printf("%s\n", ft_substr(str, 6, 5));
	printf("%s\n", ft_substr(str, 11, 5));
	printf("%s\n", ft_substr(str, 0, 0));
	printf("%s\n", ft_substr(str, 0, 100));
	printf("%s\n", ft_substr(str, 10, 0));
}
