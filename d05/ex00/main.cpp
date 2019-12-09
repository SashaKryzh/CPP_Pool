#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Freddy", 1);
        std::cout << b;
        b.decrementGrade();
        std::cout << b;
        b.incrementGrade();
        std::cout << b;
        b.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Elton", 150);
        std::cout << b;
        b.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Elton", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}