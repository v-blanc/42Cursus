/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:51 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/11 17:09:03 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  public:
	Cat(void);
	Cat(Cat const &src);
	~Cat(void);

	Brain *getBrain(void) const;

	void makeSound(void) const;

  private:
	Brain *_brain;

	Cat &operator=(Cat const &rhs);
};
