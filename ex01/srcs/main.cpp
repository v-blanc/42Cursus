/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:34:01 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 16:39:34 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(5, "Bob");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
