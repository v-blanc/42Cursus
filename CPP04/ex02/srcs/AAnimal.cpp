/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:59 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/12 15:53:53 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->_type = src._type;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}
