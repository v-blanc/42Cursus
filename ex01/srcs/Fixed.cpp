/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:01:25 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 14:35:45 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0), _isInt(true)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value), _isInt(true)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _value((int)roundf(value
		* (1 << Fixed::_bits))), _isInt(false)
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
		this->_isInt = rhs.getIsInt();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

bool Fixed::getIsInt(void) const
{
	return (this->_isInt);
}

float Fixed::toFloat(void) const
{
	if (this->_isInt == false)
		return ((float)this->_value / (1 << Fixed::_bits));
	return ((float)this->_value);
}

int Fixed::toInt(void) const
{
	if (this->_isInt == true)
		return (this->_value);
	return (this->_value >> Fixed::_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	if (rhs.getIsInt() == true)
		o << rhs.getRawBits();
	else
		o << rhs.toFloat();
	return (o);
}
