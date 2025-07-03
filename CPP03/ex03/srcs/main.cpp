/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:05:23 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/09 21:42:27 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	get_stats(const DiamondTrap &diamondtrap)
{
	std::cout << "[ " << diamondtrap.getName() << " have " << diamondtrap.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << "[ " << diamondtrap.getName() << " have " << diamondtrap.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << diamondtrap.getName() << " have " << diamondtrap.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	DiamondTrap vincent("Vincent");
	get_stats(vincent);
	vincent.attack("Zidane");
	get_stats(vincent);
	vincent.takeDamage(70);
	get_stats(vincent);
	vincent.beRepaired(1000);
	get_stats(vincent);
	std::cout << "----------------------- whoAmI() -----------------------" << std::endl;
	vincent.whoAmI();
	std::cout << std::endl;
	std::cout << "------------------- highFivesGuys() -------------------" << std::endl;
	vincent.highFivesGuys();
	std::cout << std::endl;
	std::cout << "--------------------- guardGate() ---------------------" << std::endl;
	vincent.guardGate();
	std::cout << std::endl;
	return (0);
}
