/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:57:09 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 18:02:07 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
  public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void attack(void) const;

  private:
	std::string _name;
	Weapon &_weapon;
};
