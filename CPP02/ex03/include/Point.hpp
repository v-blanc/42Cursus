/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:55:49 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 09:56:03 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"
# include <iostream>

class Point
{
  public:
	Point(void);
	Point(Fixed const x, Fixed const y);
	Point(Point const &src);
	~Point(void);

	Fixed getX(void) const;
	Fixed getY(void) const;

	Point &operator=(Point const &rhs);

  private:
	Fixed _x;
	Fixed _y;
};

std::ostream &operator<<(std::ostream &o, Point const &rhs);

#endif
