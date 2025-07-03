/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:03:57 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 19:37:36 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName() << " has no energy points!" << std::endl;
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << this->getName() << " attacks " << target;
	std::cout << ", causing " << this->getAttackDamage();
	std::cout << " points of damage! Woah!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << this->getName() << " is now in Gate keeper mode" << std::endl;
}
