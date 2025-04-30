/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:29:34 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 19:39:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
  public:
	ClapTrap(std::string name);
	~ClapTrap(void);

	std::string getName(void) const;
	unsigned int getHitPoints(void) const;
	void setHitPoints(unsigned int amount);
	unsigned int getEnergyPoints(void) const;
	void setEnergyPoints(unsigned int amount);
	unsigned int getAttackDamage(void) const;
	void setAttackDamage(unsigned int amount);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

  private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

	ClapTrap(void);
	ClapTrap(ClapTrap const &src);
	ClapTrap &operator=(ClapTrap const &rhs);
};
