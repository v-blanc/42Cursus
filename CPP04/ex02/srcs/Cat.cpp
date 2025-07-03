/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:07 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/12 15:51:00 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	std::cout << "Cat constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat const &src) : AAnimal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = src._type;
	_brain = new Brain(*src._brain);
}

Cat::~Cat(void)
{
	delete	_brain;

	std::cout << "Cat destructor called" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->_brain);
}

void Cat::makeSound(void) const
{
	std::cout << "MIAOUUUU!" << std::endl;
}
