/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:22:38 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/11 16:43:27 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
  public:
	Animal(void);
	virtual ~Animal(void);

	std::string getType(void) const;

	virtual void makeSound(void) const;

  protected:
	std::string _type;

  private:
	Animal(Animal const &src);
	Animal &operator=(Animal const &rhs);
};
