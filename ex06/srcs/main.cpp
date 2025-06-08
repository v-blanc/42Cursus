/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:12:04 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/08 18:54:46 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum	e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNKNOWN
};

e_level	getLevelEnum(const std::string &level)
{
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	return (UNKNOWN);
}

int	main(int argc, char **argv)
{
	Harl	harl;
	int		flag_speak_now;

	if (argc != 2)
	{
		std::cout << "Usage: ./harl_filter <level>" << std::endl;
		return (1);
	}
	switch (getLevelEnum(argv[1]))
	{
	case DEBUG:
		flag_speak_now = DEBUG;
		break ;
	case INFO:
		flag_speak_now = INFO;
		break ;
	case WARNING:
		flag_speak_now = WARNING;
		break ;
	case ERROR:
		flag_speak_now = ERROR;
		break ;
	default:
		flag_speak_now = UNKNOWN;
		break ;
	}
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = flag_speak_now; i < 4; i++)
	{
		harl.complain(levels[i]);
		std::cout << std::endl;
	}
	if (flag_speak_now == UNKNOWN)
		harl.complain("OTHER");
	return (0);
}
