#include "main.h"

#include <iostream>
#include "main.h"

int main() {
	std::string infos[5] = {
		"Marin", 
		"Becker", 
		"rin", 
		"123456789", 
		"I'm a student at 42."
	};
	Contact contact(infos);
	
	std::cout << "First Name: " << contact.firstName << std::endl;
	std::cout << "Last Name: " << contact.lastName << std::endl;
	std::cout << "Nickname: " << contact.nickname << std::endl;
	std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << contact.darkestSecret << std::endl;
	
	return 0;
}
