/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:43:23 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:10:11 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_H
# define DIAMONTRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
  public:
	DiamondTrap(std::string name);
	~DiamondTrap(void);

	std::string getName(void) const;
	void whoAmI(void);

  private:
	std::string _name;
	DiamondTrap(void);
	DiamondTrap(DiamondTrap const &src);
	DiamondTrap &operator=(DiamondTrap const &rhs);
};

#endif
