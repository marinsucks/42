/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:23:14 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/26 14:44:47 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <cstdlib>
#include "colors_ju.h"

int main()
{
	//Abstract class test
	Animal concrete;	// compiles
	AAnimal abstract;	// does not compile





	// Array creation
	AAnimal *animals[100];
	
	for (int i = 0; i < 50; i++)
		animals[i] = new Dog();
	for (int i = 50; i < 100; i++)
		animals[i] = new Cat();

	// Interactive test program
	std::string line = "";
	while (line != "EXIT")
	{
		std::cout << BLU << "To test the functions please enter one of the following:" << RESET << std::endl;
		std::cout << YEL << "MKSOUND" << RESET << std::endl;
		std::cout << YEL << "IDEA" << RESET << std::endl;
		std::cout << YEL << "or write 'EXIT' to exit the program" << RESET << std::endl;

		// Gets user cmd and protects against ctr+D
		std::getline(std::cin, line);
		if (std::cin.eof())
			return (0);

		if (line == "MKSOUND" || line == "IDEA")
		{
			std::cout << YEL << "Please enter the animal's index from 0 to 99" << RESET << std::endl;

			// Gets animal index and protects against ctr+D
			std::string index = "";
			std::getline(std::cin, index);
			if (std::cin.eof())
				return (0);
			int n_index = atoi(index.c_str());
			if (n_index < 0 || n_index > 99)
				std::cout << RED << "Wrong index" << RESET << std::endl;
			else {
				if (line == "MKSOUND")
					animals[n_index]->makeSound();

				if (line == "IDEA")
				{
					// Gets idea index and protects against ctr+D
					std::string idea_index = "";
					std::cout << YEL << "Please enter the idea's index from 0 to 99" << RESET << std::endl;
					std::getline(std::cin, idea_index);
					if (std::cin.eof())
						return (0);
					int n_idea_index = atoi(idea_index.c_str());
					if (n_idea_index < 0 || n_idea_index > 99)
						std::cout << RED << "Wrong index" << RESET << std::endl;
					else
						std::cout << animals[n_index]->getBrain()->getIdea(n_idea_index) << std::endl;
				}
			}
		}

		// Exits program
		if (line == "EXIT")
			break;
	}

	for (int i = 0; i < 100; i++)
		delete animals[i];

	return (0);
}
