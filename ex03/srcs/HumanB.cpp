#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::HumanB(void)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void) const
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " does not have any weapon !" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
