/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:11:20 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 20:47:14 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap bob("Bob");
	ScavTrap jim("Jim");
	std::cout << std::endl;
	std::cout << "[ " << bob.getName() << " have " << bob.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << "[ " << bob.getName() << " have " << bob.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << bob.getName() << " have " << bob.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
	std::cout << "[ " << jim.getName() << " have " << jim.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << "[ " << jim.getName() << " have " << jim.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << jim.getName() << " have " << jim.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
	{
		bob.attack("John");
		std::cout << "[ " << bob.getName() << " have " << bob.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		jim.attack("John");
		std::cout << "[ " << jim.getName() << " have " << jim.getEnergyPoints() << " energy points ]" << std::endl;
		std::cout << std::endl;
		jim.takeDamage(20);
		std::cout << "[ " << jim.getName() << " have " << jim.getHitPoints() << " hit points ]" << std::endl;
		std::cout << std::endl;
		jim.beRepaired(10);
		std::cout << "[ " << jim.getName() << " have " << jim.getHitPoints() << " hit points ]" << std::endl;
		std::cout << std::endl;
		jim.guardGate();
	}
	std::cout << std::endl;
	return (0);
}
