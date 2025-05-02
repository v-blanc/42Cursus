/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:22:41 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 12:59:12 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
  public:
	Cat(void);
	~Cat(void);

	void makeSound(void) const;

  private:
	Cat(Cat const &src);
	Cat &operator=(Cat const &rhs);
};
