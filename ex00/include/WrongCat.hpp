/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:22:46 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 13:09:13 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
	WrongCat(void);
	~WrongCat(void);

	void makeSound(void) const;

  private:
	WrongCat(WrongCat const &src);
	WrongCat &operator=(WrongCat const &rhs);
};
