/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:51:34 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 17:56:06 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon
{
  public:
	Weapon(std::string type);
	~Weapon(void);

	std::string getType(void) const;
	void setType(std::string new_type);

	Weapon(void);

  private:
	std::string _type;
};
