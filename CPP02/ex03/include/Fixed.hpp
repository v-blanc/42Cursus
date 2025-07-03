/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:55:29 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 09:55:40 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <cmath>
# include <iostream>

class Fixed
{
  public:
	Fixed(void);
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const &src);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	bool getIsInt(void) const;
	float toFloat(void) const;
	int toInt(void) const;

	Fixed &operator=(Fixed const &rhs);
	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);

  private:
	int _value;
	static const int _bits = 8;
	bool _isInt;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
