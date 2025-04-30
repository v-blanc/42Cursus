/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:29:40 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 20:46:34 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	{
		ClapTrap claptrap("Bob");
		std::cout << std::endl;
		std::cout << "[ " << claptrap.getName() << " have " << claptrap.getAttackDamage() << " attack damage ]" << std::endl;
		std::cout << "[ " << claptrap.getName() << " have " << claptrap.getHitPoints() << " hit points ]" << std::endl;
		std::cout << "[ " << claptrap.getName() << " have " << claptrap.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		claptrap.attack("NOTHING");
		std::cout << "[ Now " << claptrap.getName() << " have " << claptrap.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		claptrap.takeDamage(2);
		std::cout << "[ Now " << claptrap.getName() << " have " << claptrap.getHitPoints() << " hit points ]" << std::endl;
		std::cout << "[ Now " << claptrap.getName() << " have " << claptrap.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		claptrap.beRepaired(4);
		std::cout << "[ Now " << claptrap.getName() << " have " << claptrap.getHitPoints() << " hit points ]" << std::endl;
		std::cout << "[ Now " << claptrap.getName() << " have " << claptrap.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		claptrap.takeDamage(12);
		std::cout << "[ Now " << claptrap.getName() << " have " << claptrap.getHitPoints() << " hit points ]" << std::endl;
		std::cout << std::endl;
		claptrap.takeDamage(10000);
		std::cout << "[ Now " << claptrap.getName() << " have " << claptrap.getHitPoints() << " hit points ]" << std::endl;
	}
	std::cout << "-----------------------------------------------------------" << std::endl;
	{
		ClapTrap bob("Bob");
		std::cout << std::endl;
		std::cout << "[ " << bob.getName() << " have " << bob.getAttackDamage() << " attack damage ]" << std::endl;
		std::cout << "[ " << bob.getName() << " have " << bob.getHitPoints() << " hit points ]" << std::endl;
		std::cout << "[ " << bob.getName() << " have " << bob.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 12; i++)
		{
			bob.attack("John");
			std::cout << "[ " << bob.getName() << " have " << bob.getEnergyPoints() << " energy points ]" << std::endl;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}
