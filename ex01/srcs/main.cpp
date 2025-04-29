/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:25:22 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 11:59:10 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	string		action;

	cout << "Welcome to your AWESOME PhoneBook !" << endl;
	while (action != "EXIT")
	{
		cout << endl << "--------------------------------------------------";
		cout << endl << "Please enter an action : ADD, SEARCH or EXIT";
		cout << endl << "  > ";
		cin >> action;
		if (action == "ADD")
			phonebook.addContact();
		else if (action == "SEARCH")
			phonebook.searchContact();
	}
	return (0);
}
