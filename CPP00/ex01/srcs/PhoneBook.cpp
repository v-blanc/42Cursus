/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:55:07 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 12:39:26 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_last_contact = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::addContact(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	std::cout << std::endl;
	std::cout << "* Please enter the first name : " << std::endl << "\t> ";
	std::cin >> first_name;
	std::cout << "* Please enter the last name : " << std::endl << "\t> ";
	std::cin >> last_name;
	std::cout << "* Please enter the nickname : " << std::endl << "\t> ";
	std::cin >> nickname;
	std::cout << "* Please enter the phone number : " << std::endl << "\t> ";
	std::cin >> phone_number;
	std::cout << "* Please enter the darkest secret : " << std::endl << "\t> ";
	std::cin >> darkest_secret;
	this->contacts[this->_last_contact] = Contact(first_name, last_name,
			nickname, phone_number, darkest_secret);
	this->_last_contact = (this->_last_contact + 1) % 8;
}

static void	printInfo(std::string info)
{
	if (info.length() > 10)
		std::cout << info.substr(0, 9) << ".|";
	else
		std::cout << info << std::setw(11 - info.length()) << "|";
}

void PhoneBook::searchContact(void) const
{
	int index;

	index = 0;
	while (index < 8 && this->contacts[index].first_name != "")
	{
		std::cout << std::endl << "|#" << index + 1 << std::setw(8) << "|";
		printInfo(this->contacts[index].first_name);
		printInfo(this->contacts[index].last_name);
		printInfo(this->contacts[index].nickname);
		index++;
	}
	if (index == 0)
	{
		std::cout << std::endl << "* You have no contact in your AMAZING PhoneBook !" << std::endl;
		return ;
	}
	while (1)
	{
		std::cout << std::endl << std::endl << "* Please enter an index : ";
		std::cin >> index;
		if (index < 1 || index > 8 || contacts[index - 1].first_name == "")
			std::cout << "  Error: Invalid index";
		else
			break ;
	}
	this->contacts[index - 1].displayContact();
}
