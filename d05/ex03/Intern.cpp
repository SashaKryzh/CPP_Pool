#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &) {}

Intern &Intern::operator=(const Intern &)
{
    return *this;
}

Form *Intern::makeForm(std::string formName, std::string target) const
{
    Form *f = nullptr;

    if (formName == "shrubbery creation")
        f = new ShrubberyCreationForm(target);
    if (formName == "robotomy request")
        f = new RobotomyRequestForm(target);
    if (formName == "presidential pardon")
        f = new PresidentialPardonForm(target);

    if (f != nullptr)
        std::cout << "Intern creates " << formName << std::endl;
    else
        std::cout << "Intern don't know what is " << formName << std::endl;

    return f;
}