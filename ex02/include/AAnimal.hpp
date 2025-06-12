/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:41 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/12 15:54:09 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

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
