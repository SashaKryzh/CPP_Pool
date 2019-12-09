#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form(target, "RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src)
{
    operator=(src);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src)
    {
        Form::operator=(src);
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    checkIfAllowedToExecute(executor);
    std::cout << "SOME DRILLING NOISES... " << getTarget();
    srand(time(nullptr));
    if (rand() % 1)
        std::cout << " has been robotomized successfully.";
    else
        std::cout << " hasn't been robotomized.";
    std::cout << std::endl;
}