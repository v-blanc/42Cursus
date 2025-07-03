/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:28:44 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/08 13:28:45 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
