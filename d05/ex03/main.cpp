#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Intern billy;

        Bureaucrat freddy("Freddy", 60);

        Form *sF;
        Form *rF;
        Form *pF;
        Form *f4;

        sF = billy.makeForm("shrubbery creation", "Ralph");
        rF = billy.makeForm("robotomy request", "Bender");
        pF = billy.makeForm("presidential pardon", "Elton");
        f4 = billy.makeForm("make war in vietnam", "Darth Vader");

        std::cout << *sF << *rF << *pF << f4 << std::endl;

        freddy.executeForm(*sF);
        freddy.signForm(*sF);
        std::cout << *sF;
        freddy.executeForm(*sF);

        freddy.signForm(*rF);
        std::cout << *rF;
        freddy.executeForm(*rF);

        freddy.signForm(*pF);

        Bureaucrat trump("Trump", 1);
        trump.executeForm(*rF);
        trump.signForm(*pF);
        std::cout << *pF;
        trump.executeForm(*pF);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}