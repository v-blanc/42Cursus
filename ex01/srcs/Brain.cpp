/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:03 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/11 17:02:34 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
	this->_ideas = new std::string[100];
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	if (!src._ideas)
		return ;
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	if (this->_ideas)
		delete[] this->_ideas;
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return (this->_ideas[i]);
	return ("");
}

void Brain::setIdea(int i, std::string idea)
{
	if (i >= 0 && i < 100)
		this->_ideas[i] = idea;
}

Brain &Brain::operator=(Brain const &rhs)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}
