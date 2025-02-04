/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:14:19 by vblanc            #+#    #+#             */
/*   Updated: 2025/02/04 19:32:02 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/complex.h"

void	ft_set_complex(t_complex *c, int real, int img)
{
	c->real = real;
	c->img = img;
}

t_complex	ft_add_complex(t_complex c1, t_complex c2)
{
	t_complex	c3;

	c3.real = c1.real + c2.real;
	c3.img = c1.img + c2.img;
	return (c3);
}

t_complex	ft_mul_complex(t_complex c1, t_complex c2)
{
	t_complex	c3;

	c3.real = c1.real * c2.real - c1.img * c2.img;
	c3.img = c1.real * c2.img + c1.img * c2.real;
	return (c3);
}
int	ft_mod_complex(t_complex c)
{
	return (c.real * c.real + c.img * c.img);
}
