/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:12:39 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 20:29:06 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name),
	ScavTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	name += "_clap_name";
	this->ClapTrap::setName(name);
	this->ClapTrap::setHitPoints(FragTrap::getHitPoints());
	this->ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	this->ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->_name << std::endl;
	std::cout << "My ClapTrap name is " << this->ClapTrap::getName() << std::endl;
}
