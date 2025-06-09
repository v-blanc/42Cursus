/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:56:53 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/09 19:42:15 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	char	answer;
	float	x;
	float	y;
	Point	a;
	Point	b;
	Point	c;
	float	px;
	float	py;
	Point	p;

	std::cout << "Want to select your own triangle ? (y/n): ";
	if (std::cin >> answer && answer != 'y')
	{
		a = Point(0, 0);
		b = Point(1, 0);
		c = Point(0, 1);
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << std::endl;
			std::cout << "Enter x and y coordinates of point " << i + 1;
			std::cout << std::endl << "    x_" << (i + 1) << ": ";
			std::cin >> x;
			std::cout << "    y_" << (i + 1) << ": ";
			std::cin >> y;
			if (i == 0)
				a = Point(x, y);
			else if (i == 1)
				b = Point(x, y);
			else
				c = Point(x, y);
		}
	}
	std::cout << std::endl;
	std::cout << "> Triangle coordinates: ";
	std::cout << BLUE << a << ", " << b << ", " << c;
	std::cout << RESET << std::endl << std::endl;
	{
		std::cout << "Enter x and y coordinates of the point" << std::endl;
		std::cout << "    x: ";
		std::cin >> px;
		std::cout << "    y: ";
		std::cin >> py;
		p = Point(px, py);
		std::cout << std::endl;
		std::cout << "> Point coordinates: " << BLUE << p << std::endl;
	}
	std::cout << RESET << std::endl;
	if (bsp(a, b, c, p) == true)
		std::cout << ">> " << GREEN << "This point IS in the triangle";
	else
		std::cout << ">> " << RED << "This point IS NOT in the triangle";
	std::cout << RESET << std::endl;
	return (0);
}
