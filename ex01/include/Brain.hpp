/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:47 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/02 14:04:12 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
  public:
	Brain(void);
	Brain(Brain const &src);
	~Brain(void);

	Brain &operator=(Brain const &rhs);

  private:
	std::string *_ideas;
};
