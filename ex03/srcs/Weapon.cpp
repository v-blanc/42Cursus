/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:54:24 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 17:56:07 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::Weapon(void) : _type("")
{
}

Weapon::~Weapon(void)
{
}

std::string Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}
