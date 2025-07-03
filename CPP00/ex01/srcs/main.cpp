/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:25:22 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 12:37:44 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	PhoneBook	phonebook;

	std::string action;
	std::cout << "Welcome to your AWESOME PhoneBook !" << std::endl;
	while (action != "EXIT")
	{
		std::cout << std::endl << "--------------------------------------------------";
		std::cout << std::endl << "Please enter an action :";
		std::cout << " ADD, SEARCH or EXIT " << std::endl << "  > ";
		std::cin >> action;
		if (action == "ADD")
			phonebook.addContact();
		else if (action == "SEARCH")
			phonebook.searchContact();
	}
	return (0);
}
