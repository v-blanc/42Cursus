/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/06 12:34:11 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s\n", ft_strchr("Hello", 'H'));
	printf("%s\n", ft_strchr("Hello", 'h'));
	printf("%s\n", ft_strchr("Hello", 'l'));
	printf("%s\n", ft_strchr("Hello", 'o'));
	printf("%s\n", ft_strchr("Hello", ' '));
	printf("%s\n", ft_strchr("", ' '));
}
