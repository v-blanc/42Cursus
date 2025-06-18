/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:22:44 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:52:46 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

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

#endif
