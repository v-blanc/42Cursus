/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:12:04 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 20:56:59 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;
	int		flag_speak_now;

	if (argc != 2)
	{
		std::cout << "Usage: ./harl_filter <level>" << std::endl;
		return (1);
	}
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	flag_speak_now = 0;
	for (int i = 0; i < 4; i++)
	{
		if (argv[1] == levels[i])
			flag_speak_now = 1;
		if (flag_speak_now == 1)
		{
			harl.complain(levels[i]);
			std::cout << std::endl;
		}
	}
	if (flag_speak_now == 0)
		harl.complain("OTHER");
	return (0);
}
