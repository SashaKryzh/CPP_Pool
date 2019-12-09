#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat freddy("Freddy", 50);
        std::cout << freddy;
        Form liveAID("Live AID", 49, 48);
        std::cout << liveAID;
        freddy.signForm(liveAID);
        freddy.incrementGrade();
        std::cout << freddy;
        freddy.signForm(liveAID);
        
        Form anotherUseless(liveAID);
        std::cout << anotherUseless;
        Form anotherUseless2("Useless 2", 10, 10);;
        std::cout << anotherUseless2;
        anotherUseless2 = anotherUseless;
        std::cout << anotherUseless2;

        Form cureAIDS("Cure AIDS", 0, 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}