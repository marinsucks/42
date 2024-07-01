#include "main.h"

class PhoneBook {
	private:
		Contact contacts[8];
		int contactCount;
	public:
		void addContact(std::string infos[5]);
		void searchContact();
		void exitPhoneBook(void);
};