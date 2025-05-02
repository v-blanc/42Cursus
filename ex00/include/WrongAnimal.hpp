/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:22:38 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 13:09:36 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
  public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	virtual ~WrongAnimal(void);

	std::string getType(void) const;
	void setType(std::string type);

	void makeSound(void) const;

  private:
	std::string _type;

	WrongAnimal(WrongAnimal const &src);
	WrongAnimal &operator=(WrongAnimal const &rhs);
};
