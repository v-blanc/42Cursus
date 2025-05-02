/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:41 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 13:59:22 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
  public:
	Animal(void);
	Animal(std::string type);
	Animal(Animal const &src);
	virtual ~Animal(void);

	std::string getType(void) const;
	void setType(std::string type);

	virtual void makeSound(void) const;

  private:
	std::string _type;

	Animal &operator=(Animal const &rhs);
};
