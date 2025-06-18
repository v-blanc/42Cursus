/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:22:41 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:52:25 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

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

#endif