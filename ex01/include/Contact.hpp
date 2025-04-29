/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:27:01 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 11:58:29 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

using namespace	std;

class Contact
{
  public:
	string first_name;
	string last_name;
	string nickname;
	string phone_number;
	string darkest_secret;

	Contact(string first_name, string last_name, string nickname,
		string phone_number, string _darkest_secret);
	~Contact(void);

	void displayContact(void) const;

	Contact(void);
};
