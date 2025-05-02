/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:15 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 13:41:15 by vblanc           ###   ########.fr       */
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
			std::cout << std::endl << "> Delete " << i + 1 << std::endl;
			delete tab[i];
		}
	}
	return (0);
}
