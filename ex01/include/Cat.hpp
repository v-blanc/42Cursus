/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:51 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 13:59:07 by vblanc           ###   ########.fr       */
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

	void makeSound(void) const;

  private:
	Brain *_brain;

	Cat &operator=(Cat const &rhs);
};
