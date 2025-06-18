/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:22:46 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:53:23 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

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

#endif
