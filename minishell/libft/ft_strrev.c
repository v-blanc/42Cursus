/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:23:40 by vblanc            #+#    #+#             */
/*   Updated: 2024/11/08 12:04:24 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  Reverses the content of ’s’. */
void	ft_strrev(char *s)
{
	int		i;
	int		len_s;
	char	temp;

	len_s = ft_strlen(s) - 1;
	i = 0;
	while (i < len_s / 2)
	{
		temp = s[i];
		s[i] = s[len_s - i - 1];
		s[len_s - i - 1] = temp;
		i++;
	}
}
