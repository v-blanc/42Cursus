/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:22:44 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 13:05:09 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
  public:
	Dog(void);
	~Dog(void);

	void makeSound(void) const;

  private:
	Dog(Dog const &src);
	Dog &operator=(Dog const &rhs);
};
