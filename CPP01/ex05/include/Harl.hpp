/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:12:59 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 20:32:03 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Harl
{
  public:
	Harl(void);
	~Harl(void);

	void complain(std::string level) const;

  private:
	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;
};
