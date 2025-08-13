/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:52:26 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/04 14:15:20 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Erases the data in the ’n’ bytes of the memory starting at the location
pointed to by ’s’, by writing zeros (bytes containing '\0') to that area. */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
