/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:11 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 14:22:25 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(Dog const &src) : AAnimal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*src._brain);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete	_brain;
}

void Dog::makeSound(void) const
{
	std::cout << "WOUAF WOUAF!" << std::endl;
}
