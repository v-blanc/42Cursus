#pragma once

#include "Fixed.hpp"
#include <iostream>

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