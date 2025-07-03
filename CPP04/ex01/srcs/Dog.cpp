/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:11 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/11 17:13:25 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = src._type;
	_brain = new Brain(*src._brain);
}

Dog::~Dog(void)
{
	delete	_brain;

	std::cout << "Dog destructor called" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->_brain);
}

void Dog::makeSound(void) const
{
	std::cout << "WOUAF WOUAF!" << std::endl;
}
