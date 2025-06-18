/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:55 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:59:40 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
  public:
	Dog(void);
	Dog(Dog const &src);
	~Dog(void);

	Brain *getBrain(void) const;

	void makeSound(void) const;

  private:
	Brain *_brain;

	Dog &operator=(Dog const &rhs);
};

#endif
