/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:04:02 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 20:22:07 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
  public:
	ScavTrap(std::string name);
	~ScavTrap(void);

	void attack(const std::string &target);
	void guardGate(void);

  private:
	ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &rhs);
	ScavTrap(ScavTrap const &src);
};
