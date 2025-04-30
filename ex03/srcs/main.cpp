/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:05:23 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/30 20:47:45 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap vincent("vincent");
	std::cout << std::endl;
	std::cout << "[ " << vincent.getName() << " have " << vincent.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << vincent.getName() << " have " << vincent.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << "[ " << vincent.getName() << " have " << vincent.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------- whoAmI() -----------------------" << std::endl;
	vincent.whoAmI();
	std::cout << std::endl;
	vincent.attack("Zidane");
	std::cout << "[ " << vincent.getName() << " have " << vincent.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
	vincent.takeDamage(70);
	std::cout << "[ " << vincent.getName() << " have " << vincent.getHitPoints() << " hit points ]" << std::endl;
	std::cout << std::endl;
	vincent.beRepaired(1000);
	std::cout << "[ " << vincent.getName() << " have " << vincent.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << vincent.getName() << " have " << vincent.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
	std::cout << "------------------- highFivesGuys() -------------------" << std::endl;
	vincent.highFivesGuys();
	std::cout << std::endl;
	std::cout << "--------------------- guardGate() ---------------------" << std::endl;
	vincent.guardGate();
	std::cout << std::endl;
	return (0);
}
