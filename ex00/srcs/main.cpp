/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:22:59 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 13:15:48 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal		*meta = new Animal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();
	
	{
		std::cout << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		std::cout << std::endl;
	}
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl << "------------------------------------------" << std::endl;
	const WrongAnimal	*wmeta = new WrongAnimal();
	const WrongAnimal	*wi = new WrongCat();
	{
		std::cout << std::endl;
		std::cout << wi->getType() << " " << std::endl;
		std::cout << std::endl;
		wi->makeSound();
		wmeta->makeSound();
		std::cout << std::endl;
	}
	delete wmeta;
	delete wi;
	return (0);
}
