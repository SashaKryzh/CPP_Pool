#include <iostream>

#include "contact.hpp"

void addContact(Contact &contact)
{
	std::cout << "First name:" << std::endl;
	std::cin >> contact.firstName;
	std::cout << "Last name:" << std::endl;
	std::cin >> contact.lastName;
	std::cout << "Nickname:" << std::endl;
	std::cin >> contact.nickname;
	std::cout << "Login:" << std::endl;
	std::cin >> contact.login;
	std::cout << "Postal address:" << std::endl;
	std::cin >> contact.postalAddress;
	std::cout << "Email:" << std::endl;
	std::cin >> contact.email;
	std::cout << "Phone:" << std::endl;
	std::cin >> contact.phone;
	std::cout << "Birthday date:" << std::endl;
	std::cin >> contact.birthdayDate;
	std::cout << "Favorite meal:" << std::endl;
	std::cin >> contact.favoriteMeal;
	std::cout << "Underweare color:" << std::endl;
	std::cin >> contact.underwearColor;
	std::cout << "Darkest secrete:" << std::endl;
	std::cin >> contact.darkestSecret;

	std::cout << "Contact added!" << std::endl;
}
