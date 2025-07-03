/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:27:09 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 12:35:52 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#pragma once

#include <iomanip>
#include <iostream>
#include <string>

class PhoneBook
{
  public:
	Contact contacts[8];

	PhoneBook(void);
	~PhoneBook(void);

	void addContact(void);
	void searchContact(void) const;

  private:
	int _last_contact;
};
