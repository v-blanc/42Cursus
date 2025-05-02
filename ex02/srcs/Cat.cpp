/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:07 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 14:22:18 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(Cat const &src) : AAnimal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete	_brain;
}

void Cat::makeSound(void) const
{
	std::cout << "MIAOUUUU!" << std::endl;
}
