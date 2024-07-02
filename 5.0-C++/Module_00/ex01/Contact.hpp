#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.h"

class Contact {
public:
    Contact(std::string infos[5]) 
	  : firstName(infos[0]),
		lastName(infos[1]),
		nickname(infos[2]),
		phoneNumber(infos[3]),
		darkestSecret(infos[4]) 
		{}
    std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif
