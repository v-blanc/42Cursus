/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:03:51 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:10:08 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : virtual public ClapTrap
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

#endif
