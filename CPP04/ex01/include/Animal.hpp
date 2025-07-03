/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:41 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:57:42 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class Animal
{
  public:
	Animal(void);
	Animal(Animal const &src);
	virtual ~Animal(void);

	std::string getType(void) const;

	virtual void makeSound(void) const;

  protected:
	std::string _type;

  private:
	Animal &operator=(Animal const &rhs);
};

#endif
