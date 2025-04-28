/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:36:44 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/28 23:05:48 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(string first_name, string last_name, string nickname,
	string phone_number, string darkest_secret) : first_name(first_name),
	last_name(last_name), nickname(nickname), phone_number(phone_number),
	darkest_secret(darkest_secret)
{
	cout << endl << "  Contact added in your AWESOME PhoneBook !" << endl;
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void Contact::display_contact(void) const
{
	cout << endl << "    First name: " << this->first_name << endl;
	cout << "    Last name: " << this->last_name << endl;
	cout << "    Nickname: " << this->nickname << endl;
	cout << "    Phone number: " << this->phone_number << endl;
	cout << "    Darkest secret: " << this->darkest_secret << endl;
}
