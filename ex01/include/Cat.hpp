/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:51 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:58:06 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

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

#endif
