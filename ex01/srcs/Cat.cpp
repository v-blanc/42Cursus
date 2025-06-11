/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:07 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/11 17:50:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = src._type;
	_brain = new Brain(*src._brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete	_brain;
}

Brain *Cat::getBrain(void) const
{
	return (this->_brain);
}

void Cat::makeSound(void) const
{
	std::cout << "MIAOUUUU!" << std::endl;
}
