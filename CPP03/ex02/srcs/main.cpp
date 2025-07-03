/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:43:27 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/09 21:15:04 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

void	get_stats(const ClapTrap &claptrap)
{
	std::cout << "[ " << claptrap.getName() << " have " << claptrap.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << "[ " << claptrap.getName() << " have " << claptrap.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << claptrap.getName() << " have " << claptrap.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	ClapTrap bob("Bob");
	get_stats(bob);
	FragTrap tom("Tom");
	get_stats(tom);
	bob.attack("John");
	get_stats(bob);
	tom.attack("John");
	get_stats(tom);
	tom.takeDamage(20);
	get_stats(tom);
	tom.beRepaired(10);
	get_stats(tom);
	tom.highFivesGuys();
	std::cout << std::endl;
	return (0);
}
