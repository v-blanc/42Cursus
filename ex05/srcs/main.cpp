/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:12:04 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 20:44:38 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl.complain("DEBUG");
	std::cout << ">" << std::endl;
	harl.complain("INFO");
	std::cout << ">" << std::endl;
	harl.complain("WARNING");
	std::cout << ">" << std::endl;
	harl.complain("ERROR");
	std::cout << ">" << std::endl;
	harl.complain("OTHER");
}
