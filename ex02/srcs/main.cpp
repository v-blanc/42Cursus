/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:40:23 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 16:50:12 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	std::cout << "Memory address of `string`: " << &string << std::endl;
	std::cout << "Memory address of `stringPTR`: " << stringPTR << std::endl;
	std::cout << "Memory address of `stringREF`: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of `string`: " << string << std::endl;
	std::cout << "Value of `stringPTR`: " << *stringPTR << std::endl;
	std::cout << "Value of `stringREF`: " << stringREF << std::endl;
}
