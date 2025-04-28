/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:55:07 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/28 23:13:15 by vblanc           ###   ########.fr       */
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

void PhoneBook::add_contact(void)
{
	string	first_name;
	string	last_name;
	string	nickname;
	string	phone_number;
	string	darkest_secret;

	cout << endl;
	cout << "* Please enter the first name : " << endl << "\t> ";
	cin >> first_name;
	cout << "* Please enter the last name : " << endl << "\t> ";
	cin >> last_name;
	cout << "* Please enter the nickname : " << endl << "\t> ";
	cin >> nickname;
	cout << "* Please enter the phone number : " << endl << "\t> ";
	cin >> phone_number;
	cout << "* Please enter the darkest secret : " << endl << "\t> ";
	cin >> darkest_secret;
	this->contacts[this->_last_contact] = Contact(first_name, last_name,
			nickname, phone_number, darkest_secret);
	this->_last_contact = (this->_last_contact + 1) % 8;
}

static void	print_info(string info)
{
	if (info.length() > 10)
		cout << info.substr(0, 9) << ".|";
	else
		cout << info << setw(11 - info.length()) << "|";
}

void PhoneBook::search_contact(void) const
{
	int index;

	index = 0;
	while (index < 8 && this->contacts[index].first_name != "")
	{
		cout << endl << "|#" << index + 1 << setw(8) << "|";
		print_info(this->contacts[index].first_name);
		print_info(this->contacts[index].last_name);
		print_info(this->contacts[index].nickname);
		index++;
	}
	if (index == 0)
	{
		cout << endl << "* You have no contact in your AMAZING PhoneBook !" << endl;
		return ;
	}
	while (1)
	{
		cout << endl << endl << "* Please enter an index : ";
		cin >> index;
		if (index < 1 || index > 8 || contacts[index - 1].first_name == "")
			cout << "  Error: Invalid index";
		else
			break ;
	}
	this->contacts[index - 1].display_contact();
}
