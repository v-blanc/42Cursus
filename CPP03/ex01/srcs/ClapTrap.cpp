/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:03:03 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 19:37:50 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

void ClapTrap::setHitPoints(unsigned int amount)
{
	this->_hitPoints = amount;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

void ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->_energyPoints = amount;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attackDamage = amount;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName() << " has no energy points!" << std::endl;
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << this->getName() << " attacks " << target;
	std::cout << ", causing " << this->getAttackDamage();
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->getName() << " takes " << amount;
	std::cout << " points of damage!" << std::endl;
	if (this->getHitPoints() == 0)
	{
		std::cout << this->getName() << " is already dead... Savage!" << std::endl;
		return ;
	}
	if ((int)this->getHitPoints() - (int)amount <= 0)
	{
		this->setHitPoints(0);
		std::cout << this->getName() << " dies!" << std::endl;
		return ;
	}
	this->setHitPoints(this->getHitPoints() - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << this->getName() << " is already dead... You can't ressurect it!" << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName() << " has no energy points!" << std::endl;
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << this->getName() << " is repaired by " << amount << " points!" << std::endl;
}
