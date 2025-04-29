/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2025/04/29 19:35:15 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 4)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		return (1);
	}
	std::string const s1 = argv[2];
	std::string const s2 = argv[3];
	std::fstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	std::string str_file;
	std::string new_file = "";
	{
		std::string line;
		while (std::getline(file, line))
			str_file += line + "\n";
	}
	(std::string const) str_file;
	std::size_t offset;
	std::size_t pos;
	offset = 0;
	pos = 0;
	i = 0;
	while (offset != std::string::npos)
	{
		if (i++ == 10)
			break ;
		if (offset == 0)
			offset = str_file.find(s1);
		else
			offset = str_file.find(s1, offset + 1);
		if (offset != std::string::npos)
		{
			new_file += str_file.substr(pos, offset - pos);
			new_file += s2;
			pos = offset + s1.length();
		}
		else
			new_file += str_file.substr(pos, offset - pos);
	}
	std::cout << new_file;
	file.close();
	return (0);
}
