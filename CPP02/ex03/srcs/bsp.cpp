/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:41:34 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 16:12:30 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	determinant(Point const a, Point const b, Point const c)
{
	return ((a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX()
			- c.getX()) * (a.getY() - c.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	has_neg;
	bool	has_pos;
	float	d1;
	float	d2;
	float	d3;

	d1 = determinant(point, a, b).toFloat();
	d2 = determinant(point, b, c).toFloat();
	d3 = determinant(point, c, a).toFloat();
	has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
	has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);
	return (!(has_neg && has_pos));
}
