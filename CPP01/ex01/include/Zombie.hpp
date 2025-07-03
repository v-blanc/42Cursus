/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:20:58 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 16:33:58 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie
{
  public:
	Zombie(std::string name);
	~Zombie(void);

	void announce(void) const;

	Zombie(void);

  private:
	std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);
