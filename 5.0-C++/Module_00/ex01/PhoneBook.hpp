#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.h"
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int contactCount;
	public:
		void addContact(std::string infos[5]);
		void searchContact();
		void exitPhoneBook(void);
};

#endif
