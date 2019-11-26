#include <iostream>
#include <iomanip>

#include "contact.hpp"

int main()
{
	int contactsCount = 0;
	Contact phonebook[MAX_CONTACTS];

	while (true)
	{
		std::string input;
		std::cin >> input;

		if (input == "ADD")
		{
			if (contactsCount == MAX_CONTACTS)
			{
				std::cout << "Fuck you! You have more friends than me..." << std::endl;
			}
			else
			{
				addContact(phonebook[contactsCount]);
				contactsCount++;
			}
		}
		else if (input == "SEARCH")
		{
			showContacts(phonebook, contactsCount);
		}
		else if (input == "EXIT")
		{
			break ;
		}
	}

	return 0;
}