/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:11:20 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/09 21:08:25 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	ScavTrap jim("Jim");
	get_stats(jim);
	bob.attack("John");
	get_stats(bob);
	jim.attack("John");
	get_stats(jim);
	jim.takeDamage(20);
	get_stats(jim);
	jim.beRepaired(10);
	get_stats(jim);
	jim.guardGate();
	std::cout << std::endl;
	return (0);
}
