/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:41 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 14:28:16 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AAnimal
{
  public:
	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(AAnimal const &src);
	virtual ~AAnimal(void);

	std::string getType(void) const;
	void setType(std::string type);

	virtual void makeSound(void) const = 0;

  private:
	std::string _type;

	AAnimal &operator=(AAnimal const &rhs);
};
