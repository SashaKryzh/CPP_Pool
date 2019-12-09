#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat freddy("Freddy", 60);

        ShrubberyCreationForm sF("Ralph");
        RobotomyRequestForm rF("Bender");
        PresidentialPardonForm pF("Elton");

        std::cout << sF << rF << pF << std::endl;

        freddy.executeForm(sF);
        freddy.signForm(sF);
        std::cout << sF;
        freddy.executeForm(sF);

        freddy.signForm(rF);
        std::cout << rF;
        freddy.executeForm(rF);

        freddy.signForm(pF);

        Bureaucrat trump("Trump", 1);
        trump.signForm(pF);
        std::cout << pF;
        trump.executeForm(pF);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}