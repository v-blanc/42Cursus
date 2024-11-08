/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/07 13:33:54 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "@Hello$World*";
	char	s2[] = "@@***Hello$World@**@*@@*";

	printf("%s\n", ft_strtrim(s1, ""));
	printf("%s\n", ft_strtrim(s1, "@"));
	printf("%s\n", ft_strtrim(s1, "*"));
	printf("%s\n", ft_strtrim(s1, "$"));
	printf("%s\n", ft_strtrim(s1, "*@"));
	printf("%s\n", ft_strtrim(s1, "$@"));
	printf("%s\n", ft_strtrim(s1, "*@$"));
	printf("%s\n", ft_strtrim(s2, "@"));
	printf("%s\n", ft_strtrim(s2, "*"));
	printf("%s\n", ft_strtrim(s2, "*@"));
}
