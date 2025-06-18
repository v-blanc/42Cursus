/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:01:10 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 09:55:05 by vblanc           ###   ########.fr       */
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

	Fixed &operator=(Fixed const &rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	bool getIsInt(void) const;
	float toFloat(void) const;
	int toInt(void) const;

  private:
	int _value;
	static const int _bits = 8;
	bool _isInt;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
