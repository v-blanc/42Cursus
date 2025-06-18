/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:41 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:58:59 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>
# include <string>

class AAnimal
{
  public:
	AAnimal(void);
	AAnimal(AAnimal const &src);
	virtual ~AAnimal(void);

	std::string getType(void) const;

	virtual void makeSound(void) const = 0;

  protected:
	std::string _type;

  private:
	AAnimal &operator=(AAnimal const &rhs);
};

#endif
