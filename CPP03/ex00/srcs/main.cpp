/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:29:40 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/09 20:50:36 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	get_stats(const ClapTrap &claptrap)
{
	std::cout << "[ " << claptrap.getName() << " have " << claptrap.getAttackDamage() << " attack damage ]" << std::endl;
	std::cout << "[ " << claptrap.getName() << " have " << claptrap.getHitPoints() << " hit points ]" << std::endl;
	std::cout << "[ " << claptrap.getName() << " have " << claptrap.getEnergyPoints() << " energy points ]" << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	{
		ClapTrap claptrap("Bob");
		get_stats(claptrap);
		claptrap.attack("NOTHING");
		get_stats(claptrap);
		claptrap.takeDamage(2);
		get_stats(claptrap);
		claptrap.beRepaired(4);
		get_stats(claptrap);
		claptrap.takeDamage(12);
		get_stats(claptrap);
		claptrap.beRepaired(2);
		get_stats(claptrap);
		claptrap.takeDamage(10000);
		get_stats(claptrap);
	}
	std::cout << "-----------------------------------------------------------" << std::endl;
	{
		ClapTrap bob("Bob");
		get_stats(bob);
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
