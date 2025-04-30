/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:42:52 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 19:46:52 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
  public:
	FragTrap(std::string name);
	~FragTrap(void);

	void highFivesGuys(void);

  private:
	FragTrap(void);
	FragTrap(FragTrap const &src);
	FragTrap &operator=(FragTrap const &rhs);
};
