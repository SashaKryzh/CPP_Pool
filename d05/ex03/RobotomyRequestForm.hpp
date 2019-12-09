#if !defined(ROBOTOMY_REQUESt_FORM_HPP)
#define ROBOTOMY_REQUESt_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();

    RobotomyRequestForm(const RobotomyRequestForm &);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &);

    void execute(Bureaucrat const &executor) const;
};

#endif // ROBOTOMY_REQUESt_FORM_HPP
