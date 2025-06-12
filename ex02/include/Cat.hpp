/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:51 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/12 15:49:43 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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
