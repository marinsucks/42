/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:37:36 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/05 12:11:33 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void)
{
	this->_contacts_nb = 0;
	this->_index = 0;
}

std::string getContactInfo(std::string info)
{
	std::string buff;

	while (buff.empty())
	{
		std::cout << CYAN << info << NC;
		std::getline(std::cin, buff);
		if (buff.empty())
			std::cout << RED << "Please enter a valid input." << NC << std::endl;
	}
	return (buff);
}

void PhoneBook::addContact(void)
{
	std::string buff;

	buff = getContactInfo("First Name: ");
	this->contacts[_index].setFirstName(buff);
	
	buff = getContactInfo("Last Name: ");
	this->contacts[_index].setLastName(buff);
	
	buff = getContactInfo("Nickname: ");
	this->contacts[_index].setNickname(buff);
	
	buff = getContactInfo("Phone Number: ");
	this->contacts[_index].setPhoneNumber(buff);
	
	buff = getContactInfo("Your Darkest Secret: ");
	this->contacts[_index].setDarkestSecret(buff);

	if (this->_contacts_nb < 7)
		this->_contacts_nb++;
	std::cout << LGREEN << "Contact " << GREEN;
	std::cout << this->contacts[_index].getFirstName() << " ";
	std::cout << this->contacts[_index].getLastName() << " ";
	std::cout << LGREEN <<"has been successfully added to the phone book.";
	std::cout << NC << std::endl;
	this->_index = (this->_index + 1) % 8;
}

void displayContacts(Contact *contacts)
{
	std::string pipe = "\033[1;36m|\033[0m";

	std::cout << CYAN << "     index| firstname|  lastname|  nickname" << NC << std::endl;
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
	std::string input;
	
	displayContacts(this->contacts);

	std::cout << CYAN << "Contact id: " << NC;
	std::getline(std::cin, input);
	int i = input[0] - '0';
	if (input.length() != 1 || i < 0 || i >= this->_contacts_nb) 
	{
		std::cout << RED << "Invalid index." << NC << std::endl;
		return;
	}
	
	// Clear the screen and display the contact the contact
	std::cout << "\033[2K";
	for (int x = 0; x < 10; x++)
		std::cout << "\033[A\033[2K";
	std::cout << CYAN << "First Name:     " << NC << this->contacts[i].getFirstName() << std::endl;
	std::cout << CYAN << "Last Name:      " << NC << this->contacts[i].getLastName() << std::endl;
	std::cout << CYAN << "Nickname:       " << NC << this->contacts[i].getNickname() << std::endl;
	std::cout << CYAN << "Phone Number:   " << NC << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << CYAN << "Darkest Secret: " << NC << this->contacts[i].getDarkestSecret() << std::endl;
}

void PhoneBook::exitPhoneBook(void)
{
	std::cout << std::endl;

	std::cout << MAGENTA << "B" << CYAN << "Y" << MAGENTA << "E " << " ";
	std::cout << CYAN << "B" << MAGENTA << "Y" << CYAN << "E " << " ";
	std::cout << MAGENTA << "!" << CYAN << "!" << MAGENTA << "!" << std::endl;
	std::cout << "\033[0m" << std::endl;
}

