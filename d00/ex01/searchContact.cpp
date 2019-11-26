#include <iostream>
#include <iomanip>

#include "contact.hpp"

std::string truncate(std::string str, size_t width)
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}

void showContacts(Contact *contacts, int count)
{
	int input;

	if (count == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}

	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < count; i++)
	{
		Contact current = contacts[i];
		std::cout << std::setw(10) << i << '|';
		std::cout << std::setw(10) << truncate(current.firstName, 10) << '|';
		std::cout << std::setw(10) << truncate(current.lastName, 10) << '|';
		std::cout << std::setw(10) << truncate(current.nickname, 10);
		std::cout << std::endl;
	}

	std::cout << "Select desired contact (index): ";
	std::cin >> input;
	std::cout << std::endl;

	if (std::cin.good() && input >= 0 && input < count)
	{
		contacts[input].showContact();
	}
	else
	{
		std::cin.clear();
		std::cout << "Bad input. Break." << std::endl;
	}
}

void Contact::showContact()
{
	std::cout << "//////////////////////////" << std::endl;
	std::cout << firstName << std::endl;
	std::cout << lastName << std::endl;
	std::cout << nickname << std::endl;
	std::cout << login << std::endl;
	std::cout << postalAddress << std::endl;
	std::cout << email << std::endl;
	std::cout << phone << std::endl;
	std::cout << birthdayDate << std::endl;
	std::cout << favoriteMeal << std::endl;
	std::cout << underwearColor << std::endl;
	std::cout << darkestSecret << std::endl;
	std::cout << "//////////////////////////" << std::endl;
}