/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:15:11 by vblanc            #+#    #+#             */
/*   Updated: 2024/10/10 15:42:18 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!big || !little)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (*big && ft_strncmp(big, little, len) != 0 && len-- > 0)
		big++;
	if (*big == '\0' || len == 0)
		return (NULL);
	return ((char *)big);
}
