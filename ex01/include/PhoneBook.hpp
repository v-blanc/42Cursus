/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:27:09 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/28 23:09:25 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#pragma once

#include <iomanip>
#include <iostream>
#include <string>

using namespace	std;

class PhoneBook
{
  public:
	Contact contacts[8];

	PhoneBook(void);
	~PhoneBook(void);
	void add_contact(void);
	void search_contact(void) const;

  private:
	int _last_contact;
};
