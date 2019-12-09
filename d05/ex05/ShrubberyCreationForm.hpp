#if !defined(SHRUBBERY_CREATION_FORM_HPP)
#define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(const ShrubberyCreationForm &);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

    void execute(Bureaucrat const &executor) const;
};

#endif // SHRUBBERY_CREATION_FORM_HPP
