#ifndef CONTACT_HPP
#define CONTACT_HPP

#define MAX_CONTACTS 8

class Contact
{
public:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string login;
	std::string postalAddress;
	std::string email;
	std::string phone;
	std::string birthdayDate;
	std::string favoriteMeal;
	std::string underwearColor;
	std::string darkestSecret;

	void showContact()
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
};

void addContact(Contact &contact);
void showContacts(Contact *contacts, int count);

#endif