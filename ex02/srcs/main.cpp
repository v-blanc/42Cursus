/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:43:27 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 20:47:30 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap bob("Bob");
	FragTrap tom("Tom");
	std::cout << std::endl;
	std::cout << "[ " << bob.getName() << " have " << bob.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << "[ " << bob.getName() << " have " << bob.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << bob.getName() << " have " << bob.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
	std::cout << "[ " << tom.getName() << " have " << tom.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << "[ " << tom.getName() << " have " << tom.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << tom.getName() << " have " << tom.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
	{
		bob.attack("John");
		std::cout << "[ " << bob.getName() << " have " << bob.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		tom.attack("John");
		std::cout << "[ " << tom.getName() << " have " << tom.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		tom.takeDamage(20);
		std::cout << "[ " << tom.getName() << " have " << tom.getHitPoints() << " hit points ]" << std::endl;
		std::cout << std::endl;
		tom.beRepaired(10);
		std::cout << "[ " << tom.getName() << " have " << tom.getHitPoints() << " hit points ]" << std::endl;
		std::cout << std::endl;
		tom.highFivesGuys();
	}
	std::cout << std::endl;
	return (0);
}
