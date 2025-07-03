/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:22:38 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:53:10 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>
# include <string>

class WrongAnimal
{
  public:
	WrongAnimal(void);
	virtual ~WrongAnimal(void);

	std::string getType(void) const;

	void makeSound(void) const;

  protected:
	std::string _type;

  private:
	WrongAnimal(WrongAnimal const &src);
	WrongAnimal &operator=(WrongAnimal const &rhs);
};

#endif
