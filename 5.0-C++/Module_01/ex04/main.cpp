/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:17:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/09 14:21:27 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	file_replace(std::string str, char *argv[])
{
	size_t			start;

	std::ofstream outfile((std::string(argv[1]) + ".replace").c_str());
	if (!outfile.is_open()) 
	{
		std::cerr << "Failed to open the output file." << std::endl;
		return ;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		start = str.find(argv[2], i);
		if (start != std::string::npos && start == i)
		{
			outfile << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
}

int main(int argc, char *argv[])
{
	std::string		str;
	char			c;

	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <arg1> <arg2>" << std::endl;
		return 1;
	}

	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		std::cerr << argv[1] << ": No such file or directory" << std::endl;
		return 1;
	}

	while(!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	file_replace(str, argv);

	infile.close();
	return 0;
}
