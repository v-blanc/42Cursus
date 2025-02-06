/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:50:25 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/06 06:54:09 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_dtoa_2f(double f)
{
	char	*str;
	char	*tmp_int;
	char	*tmp_float;

	str = ft_calloc(sizeof(char), 30);
	if (f < 0)
		str[0] = '-';
	tmp_int = ft_itoa(ft_abs((int)f));
	tmp_float = ft_itoa((int)ft_abs((f - (int)f) * 100));
	str = ft_strjoin(str, tmp_int);
	str = ft_strjoin(str, ".");
	if (ft_strlen(tmp_float) == 1)
		str = ft_strjoin(str, "00");
	else
		str = ft_strjoin(str, tmp_float);
	free(tmp_int);
	free(tmp_float);
	return (str);
}
