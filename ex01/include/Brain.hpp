/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:18:47 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/18 14:57:44 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
  public:
	Brain(void);
	Brain(Brain const &src);
	~Brain(void);

	std::string getIdea(int i) const;
	void setIdea(int i, std::string idea);

	Brain &operator=(Brain const &rhs);

  private:
	std::string *_ideas;
};

#endif
