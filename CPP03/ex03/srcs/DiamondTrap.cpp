/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:12:39 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/09 21:53:14 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
	FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->ClapTrap::setHitPoints(FragTrap::getHitPoints());
	this->ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	this->ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

std::string DiamondTrap::getName(void) const
{
	return (this->_name);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->getName() << std::endl;
	std::cout << "My ClapTrap name is " << this->ClapTrap::getName() << std::endl;
}
