/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:36:44 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 12:36:30 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name,
	std::string nickname, std::string phone_number,
	std::string darkest_secret) : first_name(first_name), last_name(last_name),
	nickname(nickname), phone_number(phone_number),
	darkest_secret(darkest_secret)
{
	std::cout << std::endl << "  Contact added in your AWESOME PhoneBook !" << std::endl;
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void Contact::displayContact(void) const
{
	std::cout << std::endl << "    First name: " << this->first_name << std::endl;
	std::cout << "    Last name: " << this->last_name << std::endl;
	std::cout << "    Nickname: " << this->nickname << std::endl;
	std::cout << "    Phone number: " << this->phone_number << std::endl;
	std::cout << "    Darkest secret: " << this->darkest_secret << std::endl;
}
