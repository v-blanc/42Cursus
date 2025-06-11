/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:15 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/11 17:49:43 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();
		
		std::cout << std::endl;
		delete i;
		delete j;
	}
	std::cout << "***********************************" <<std::endl;
	{
		const Animal	*tab[10];
		for (int i = 0; i < 5; i++)
		{
			std::cout << std::endl << "> Create Dog " << i + 1 << std::endl;
			tab[i] = new Dog();
		}
		for (int i = 5; i < 10; i++)
		{
			std::cout << std::endl << "> Create Cat " << i + 1 << std::endl;
			tab[i] = new Cat();
		}
		std::cout << "------------------------------------" <<std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << std::endl << "> tab[" << i << "]:" << std::endl;
			std::cout << "> Type " << std::endl;
			std::cout << tab[i]->getType() << std::endl;
			std::cout << "> Sound " << std::endl;
			tab[i]->makeSound();
		}
		std::cout << "------------------------------------" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << std::endl << "> Delete " << i + 1 << std::endl;
			delete tab[i];
		}
	}
	std::cout << "------------------------------------" << std::endl;
	{
		const Dog	*dog = new Dog();
		std::cout << std::endl << "Add idea to Dog's brain" << std::endl << std::endl;
		dog->getBrain()->setIdea(0, "Idea 0");
		dog->Dog::getBrain()->setIdea(5, "Idea 5");
		const Dog	*tmp = new Dog(*dog);
		std::cout << std::endl << "> Copy" << std::endl;
		std::cout << "> Type " << tmp->getType() << std::endl;
		std::cout << "> Sound " << std::endl;
		tmp->makeSound();
		std::cout << "> Brain " << std::endl;
		for (int i = 0; i <= 5; i++)
		{
			std::cout << "> Idea" << i << ": " << tmp->getBrain()->getIdea(i) << std::endl;
		}
		delete dog;
		delete tmp;
	}
	return (0);
}
