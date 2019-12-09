#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Intern idiotOne;
    Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
    Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
    OfficeBlock ob;

    try
    {
        ob.doBureaucracy("Some shitty bureaucracy", "Gretta");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    ob.setIntern(idiotOne);
    ob.setSigner(bob);
    ob.setExecutor(hermes);

    try
    {
        ob.doBureaucracy("presidential pardon", "Kim Jong-un");
        ob.doBureaucracy("robotomy request", "Bender");
        ob.doBureaucracy("shrubbery creation", "Some creature");

        std::cout << "\nSet SuperExecutor\n" << std::endl;

        Bureaucrat super("SuperCrat", 1);
        ob.setSigner(super);
        ob.setExecutor(super);

        ob.doBureaucracy("presidential pardon", "Kim Jong-un");
        ob.doBureaucracy("robotomy request", "Bender");
        ob.doBureaucracy("shrubbery creation", "Some creature");

        ob.doBureaucracy("mutant pig termination", "Pigley");
    }
    catch (OfficeBlock::UnknownFormName &e)
    {
        std::cout << "WTF do you want ?!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}