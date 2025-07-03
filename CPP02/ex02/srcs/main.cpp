/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:56:18 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/09 19:25:17 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed	a;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(10);
	Fixed d(2.55f);
	{
		// Affichage des valeurs
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "d: " << d << std::endl;
	}
	std::cout << std::endl;
	{
		// Test opérateurs arithmétiques
		std::cout << "c + d = " << (c + d) << std::endl;
		std::cout << "c - d = " << (c - d) << std::endl;
		std::cout << "c * d = " << (c * d) << std::endl;
		std::cout << "c / d = " << (c / d) << std::endl;
	}
	std::cout << std::endl;
	{
		// Test opérateurs de comparaison
		std::cout << "c > d: " << (c > d) << std::endl;
		std::cout << "c < d: " << (c < d) << std::endl;
		std::cout << "c >= d: " << (c >= d) << std::endl;
		std::cout << "c <= d: " << (c <= d) << std::endl;
		std::cout << "c == d: " << (c == d) << std::endl;
		std::cout << "c != d: " << (c != d) << std::endl;
	}
	std::cout << std::endl;
	{
		// Test opérateurs d'incrémentation et décrémentation
		Fixed e(0.05f);
		std::cout << "e: " << e << std::endl;
		std::cout << "++e: " << ++e << std::endl;
		std::cout << "e: " << e << std::endl;
		std::cout << "e++: " << e++ << std::endl;
		std::cout << "e: " << e << std::endl;
		std::cout << "--e: " << --e << std::endl;
		std::cout << "e: " << e << std::endl;
		std::cout << "e--: " << e-- << std::endl;
		std::cout << "e: " << e << std::endl;
	}
	std::cout << std::endl;
	{
		// Test min et max
		Fixed const e(0.05f);
		std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
		std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
		std::cout << "min(b, e): " << Fixed::min(b, e) << std::endl;
		std::cout << "max(b, e): " << Fixed::max(b, e) << std::endl;
	}
	return (0);
}
