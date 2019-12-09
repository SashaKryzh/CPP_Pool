#include "CentralBureaucracy.hpp"
#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    CentralBureaucracy central;

    Bureaucrat b1("b1", 50);
    Bureaucrat b2("b2", 150);
    Bureaucrat b3("b3", 10);
    Bureaucrat b4("b4", 1);
    Bureaucrat b5("b5", 77);
    Bureaucrat b6("b6", 140);
    Bureaucrat b7("b7", 30);
    Bureaucrat b8("b8", 42);
    Bureaucrat b9("b9", 52);
    Bureaucrat b10("b10", 99);

    central.queueUp("Q1");
    central.queueUp("Q2");
    central.queueUp("Q3");
    central.queueUp("Q4");
    central.queueUp("Q5");
    central.queueUp("Q6");
    central.queueUp("Q7");
    central.queueUp("Q8");
    central.queueUp("Q9");
    central.queueUp("Q10");
    central.queueUp("Q11");
    central.queueUp("Q12");
    central.queueUp("Q13");
    central.queueUp("Q14");
    central.queueUp("Q15");
    central.queueUp("Q16");

    central.feedBureaucrat(b1);
    central.feedBureaucrat(b2);
    central.feedBureaucrat(b3);
    central.feedBureaucrat(b4);
    central.feedBureaucrat(b5);
    central.feedBureaucrat(b6);
    central.feedBureaucrat(b7);
    central.feedBureaucrat(b8);
    central.feedBureaucrat(b9);
    central.feedBureaucrat(b10);

    try
    {
        central.doBureaucracy();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}