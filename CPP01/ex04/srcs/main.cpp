/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:27:06 by vblanc            #+#    #+#             */
/*   Updated: 2025/06/17 20:09:27 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string const s1 = argv[2];
	std::string const s2 = argv[3];
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file " << filename << std::endl;
		return (1);
	}
	filename += ".replace";
	std::ofstream new_file(filename.c_str());
	if (!new_file.is_open())
	{
		std::cout << "Error: could not open file " << filename << std::endl;
		return (1);
	}
	std::string line;
	std::string new_line;
	std::size_t offset;
	std::size_t pos;
	while (std::getline(file, line))
	{
		new_line = "";
		offset = 0;
		pos = 0;
		while (offset != std::string::npos)
		{
			offset = line.find(s1, pos);
			if (offset != std::string::npos)
			{
				new_line += line.substr(pos, offset - pos);
				new_line += s2;
				pos = offset + s1.length();
				offset++;
			}
			else
				new_line += line.substr(pos, offset - pos);
		}
		new_line += "\n";
		new_file << new_line;
	}
	new_file.close();
	file.close();
	return (0);
}
