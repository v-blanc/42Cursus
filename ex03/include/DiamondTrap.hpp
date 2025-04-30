#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
  public:
	DiamondTrap(std::string name);
	~DiamondTrap(void);

	void whoAmI(void);

  private:
	std::string _name;
	DiamondTrap(void);
	DiamondTrap(DiamondTrap const &src);
	DiamondTrap &operator=(DiamondTrap const &rhs);
};
