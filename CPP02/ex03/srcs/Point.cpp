/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:57:32 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 09:57:33 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
}

Point::Point(Point const &src)
{
	*this = src;
}

Point::~Point(void)
{
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}

Point &Point::operator=(Point const &rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Point const &rhs)
{
	o << "(" << rhs.getX() << ", " << rhs.getY() << ")";
	return (o);
}