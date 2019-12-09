#if !defined(INTERN_HPP)
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
public:
    Intern();
    ~Intern();

    Intern(const Intern &);
    Intern &operator=(const Intern &);

    Form *makeForm(std::string formName, std::string target) const;
};

#endif // INTERN_HPP
