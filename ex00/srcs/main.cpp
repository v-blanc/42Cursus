/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:29:40 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 18:59:10 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Bob");
	std::cout << std::endl;
	std::cout << "[ " << claptrap.getName() << " has " << claptrap.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << "[ " << claptrap.getName() << " has " << claptrap.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
	{
		claptrap.attack("NOTHING");
		std::cout << std::endl;
		claptrap.takeDamage(2);
		std::cout << "[ Now " << claptrap.getName() << " has " << claptrap.getHitPoints() << " hit points ]" << std::endl;
		std::cout << "[ Now " << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		claptrap.beRepaired(4);
		std::cout << "[ Now " << claptrap.getName() << " has " << claptrap.getHitPoints() << " hit points ]" << std::endl;
		std::cout << "[ Now " << claptrap.getName() << " has " << claptrap.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		claptrap.takeDamage(12);
		std::cout << "[ Now " << claptrap.getName() << " has " << claptrap.getHitPoints() << " hit points ]" << std::endl;
		std::cout << std::endl;
		claptrap.takeDamage(10000);
		std::cout << "[ Now " << claptrap.getName() << " has " << claptrap.getHitPoints() << " hit points ]" << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
