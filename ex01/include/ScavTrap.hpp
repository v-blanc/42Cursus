/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:03:50 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 13:31:08 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
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

#endif
