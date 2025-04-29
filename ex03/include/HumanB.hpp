#pragma once

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
  public:
	HumanB(std::string name);
	~HumanB(void);

	void attack(void) const;
	void setWeapon(Weapon &weapon);

	HumanB(void);

  private:
	std::string _name;
	Weapon *_weapon;
};
