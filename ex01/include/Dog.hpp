/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:55 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 13:59:10 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  public:
	Dog(void);
	Dog(Dog const &src);
	~Dog(void);

	void makeSound(void) const;

  private:
	Brain *_brain;

	Dog &operator=(Dog const &rhs);
};
