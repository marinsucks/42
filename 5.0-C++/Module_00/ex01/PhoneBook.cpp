/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:37:36 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/04 17:19:36 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void)
{
	this->contacts_nb = 0;
	this->index = 0;
}

void PhoneBook::addContact(void)
{
	std::string	buff;

	std::cout << "\033[1;36mFirst Name:\033[0m ";
	std::getline(std::cin, buff);
	this->contacts[index].setFirstName(buff);
	std::cout << "\033[1;36mLast Name:\033[0m ";
	std::getline(std::cin, buff);
	this->contacts[index].setLastName(buff);
	std::cout << "\033[1;36mNickname:\033[0m ";
	std::getline(std::cin, buff);
	this->contacts[index].setNickname(buff);
	std::cout << "\033[1;36mPhone Number:\033[0m ";
	std::getline(std::cin, buff);
	this->contacts[index].setPhoneNumber(buff);
	std::cout << "\033[1;36mYour Darkest Secret:\033[0m ";
	std::getline(std::cin, buff);
	this->contacts[index].setDarkestSecret(buff);
	if (this->contacts_nb < 7)
		this->contacts_nb++;
	this->index = (this->index + 1) % 8;
	std::cout << "\033[0;32mContact \033[1;32m";
	std::cout << this->contacts[index].getFirstName() << " ";
	std::cout << this->contacts[index].getLastName();
	std::cout << "\033[0;32m has been successfully added to the phone book.\033[0m" << std::endl;
}

void displayContacts(Contact *contacts)
{
	std::string	blue = "\033[1;36m";
	std::string	nc = "\033[0m";
	std::string pipe = "\033[1;36m|\033[0m";

	std::cout << blue << "     index| firstname|  lastname|  nickname" << nc << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << pipe;

		std::string firstname = contacts[i].getFirstName();
		std::string lastname = contacts[i].getLastName();
		std::string nickname = contacts[i].getNickname();

		firstname = firstname.length() > 10 ? firstname.substr(0, 9) + "." : firstname;
		lastname = lastname.length() > 10 ? lastname.substr(0, 9) + "." : lastname;
		nickname = nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname;

		std::cout << std::setw(10) << firstname << pipe;
		std::cout << std::setw(10) << lastname << pipe;
		std::cout << std::setw(10) << nickname << std::endl;
	}
}

void PhoneBook::searchContact(void)
{
	std::string	blue = "\033[1;36m";
	std::string	red = "\033[1;31m";
	std::string	nc = "\033[0m";
	std::string input;
	
	displayContacts(this->contacts);

	std::cout << blue << "Contact id: " << nc;
	std::getline(std::cin, input);
	int i = input[0] - '0';
	if (input.length() != 1 || i < 0 || i >= this->contacts_nb) 
	{
		std::cout << red << "Invalid index." << nc << std::endl;
		return;
	}
	
	// Clear the screen and display the contact the contact
	for (int x = 0; x < 10; x++)
		std::cout << "\033[A\033[2K";
	std::cout << blue << "First Name:     " << nc << this->contacts[i].getFirstName() << std::endl;
	std::cout << blue << "Last Name:      " << nc << this->contacts[i].getLastName() << std::endl;
	std::cout << blue << "Nickname:       " << nc << this->contacts[i].getNickname() << std::endl;
	std::cout << blue << "Phone Number:   " << nc << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << blue << "Darkest Secret: " << nc << this->contacts[i].getDarkestSecret() << std::endl;
}

void PhoneBook::exitPhoneBook(void)
{
	std::cout << std::endl;
	std::cout << "\033[1;35mB";
	std::cout << "\033[1;36mY";
	std::cout << "\033[1;35mE ";
	std::cout << "\033[1;36mB";
	std::cout << "\033[1;35mY";
	std::cout << "\033[1;36mE ";
	std::cout << "\033[1;35m!";
	std::cout << "\033[1;36m!";
	std::cout << "\033[1;35m!";
	std::cout << "\033[0m" << std::endl;
}

