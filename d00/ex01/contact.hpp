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

	void showContact(void);
};

void addContact(Contact &contact);
void showContacts(Contact *contacts, int count);

#endif