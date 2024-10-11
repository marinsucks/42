/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:28:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/08 17:28:46 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "colors_ju.h"

int main()
{
	std::string line = "";

	// Enters the program
	std::cout << BBLU << "Welcome to Happy Animal Hotel" << RESET << std::endl;

	// Loop to interact with user
	while (line != "EXIT")
	{
		std::cout << BLU << "To test the functions please enter one of the following:" << RESET << std::endl;
		std::cout << BYEL << "NDOG\t" << YEL << "-> Create a Dog object" << RESET << std::endl;
		std::cout << BYEL << "NCAT\t" << YEL << "-> Create a Cat object" << RESET << std::endl;
		std::cout << BYEL << "NANIMAL\t" << YEL << "-> Create an Animal object" << RESET << std::endl;
		std::cout << BYEL << "SDOG\t" << YEL << "-> Create and make sound with a Dog object" << RESET << std::endl;
		std::cout << BYEL << "SCAT\t" << YEL << "-> Create and make sound with a Cat object" << RESET << std::endl;
		std::cout << BYEL << "SANIMAL\t" << YEL << "-> Create and make sound with an Animal object" << RESET << std::endl;
		std::cout << BYEL << "WRONG\t" << YEL << "-> Test polymorphism with WrongAnimal, Dog, and WrongCat objects" << RESET << std::endl;
		std::cout << BYEL << "SUBJ\t" << YEL << "-> Test polymorphism with Animal, Dog, and Cat objects" << RESET << std::endl;
		std::cout << BYEL << "EXIT\t" << YEL << "-> Exit the program." << RESET << std::endl;

		// Gets user cmd and protects against ctr+D
		std::getline(std::cin, line);
		if (std::cin.eof())
			return (0);

		// Gets user input for the name if user wants to create a Zombie
		if (line == "NDOG" || line == "NCAT" || line == "NANIMAL")
		{
			// Creates Animal on the stack
			if (line == "NDOG")
				Dog dog;

			if (line == "NCAT")
				Cat cat;

			if (line == "NANIMAL")
				Animal animal;
		}

		if (line == "SDOG" || line == "SCAT" || line == "SANIMAL")
		{
			// Creates Animal on the stack
			if (line == "SDOG")
			{
				Dog dog;
				dog.makeSound();
			}

			if (line == "SCAT")
			{
				Cat cat;
				cat.makeSound();
			}

			if (line == "SANIMAL")
			{
				Animal animal;
				animal.makeSound();
			}
		}

		if (line == "WRONG")
		{
			const WrongAnimal *meta = new WrongAnimal();
			const Animal *j = new Dog();
			const WrongAnimal *i = new WrongCat();
			std::cout << j->getType() << " " << std::endl;
			std::cout << i->getType() << " " << std::endl;
			i->makeSound(); // will not output the cat sound!
			j->makeSound();
			meta->makeSound();
			delete (meta);
			delete (i);
			delete (j);
		}

		if (line == "SUBJ")
		{
			const Animal *meta = new Animal();
			const Animal *j = new Dog();
			const Animal *i = new Cat();
			std::cout << j->getType() << " " << std::endl;
			std::cout << i->getType() << " " << std::endl;
			i->makeSound(); // will output the cat sound!
			j->makeSound();
			meta->makeSound();
			delete (meta);
			delete (i);
			delete (j);
		}

		// Exits program
		if (line == "EXIT")
			break;

	}
	return (0);
}
