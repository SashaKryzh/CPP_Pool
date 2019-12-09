#if !defined(PRESIDENTIAL_PARDON_FORM_HPP)
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();

    PresidentialPardonForm(const PresidentialPardonForm &);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &);

    void execute(Bureaucrat const &executor) const;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
