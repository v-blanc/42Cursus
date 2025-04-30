/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:35:20 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 15:35:21 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0), _isInt(true)
{
}

Fixed::Fixed(int const value) : _value(value), _isInt(true)
{
}

Fixed::Fixed(float const value) : _value((int)roundf(value
		* (1 << Fixed::_bits))), _isInt(false)
{
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
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

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
		this->_isInt = rhs.getIsInt();
	}
	return (*this);
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	if (rhs.toFloat() == 0)
	{
		std::cout << "Division by zero, you what to explode the universe !?";
		std::cout << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	*this = Fixed((float const)(this->toFloat() + 0.00390625));
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	*this = Fixed((float const)(this->toFloat() + 0.00390625));
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	*this = Fixed((float const)(this->toFloat() - 0.00390625));
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	*this = Fixed((float const)(this->toFloat() - 0.00390625));
	return (tmp);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	if (rhs.getIsInt() == true)
		o << rhs.getRawBits();
	else
		o << rhs.toFloat();
	return (o);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}
