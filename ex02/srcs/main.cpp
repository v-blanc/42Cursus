/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:43:27 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 19:48:59 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap bob("Bob");
	FragTrap tom("Tom");
	std::cout << std::endl;
	std::cout << "[ " << bob.getName() << " has " << bob.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << "[ " << bob.getName() << " has " << bob.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << bob.getName() << " has " << bob.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
	std::cout << "[ " << tom.getName() << " has " << tom.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << "[ " << tom.getName() << " has " << tom.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << tom.getName() << " has " << tom.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
	{
		bob.attack("John");
		std::cout << "[ " << bob.getName() << " has " << bob.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		tom.attack("John");
		std::cout << "[ " << tom.getName() << " has " << tom.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		tom.takeDamage(20);
		std::cout << "[ " << tom.getName() << " has " << tom.getHitPoints() << " hit points ]" << std::endl;
		std::cout << std::endl;
		tom.beRepaired(10);
		std::cout << "[ " << tom.getName() << " has " << tom.getHitPoints() << " hit points ]" << std::endl;
		std::cout << std::endl;
		tom.highFivesGuys();
	}
	std::cout << std::endl;
	return (0);
}
