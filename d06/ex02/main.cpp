#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    srand(time(NULL));
    int r = rand() % 3;
    switch (r)
    {
    case 0:
        return new A();
        break;

    case 1:
        return new B();
        break;

    default:
        return new C();
        break;
    }
}

void identify_from_pointer(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        static_cast<void>(a);
    }
    catch(const std::exception& e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            static_cast<void>(b);
        }
        catch(const std::exception& e)
        {
            std::cout << "C" << std::endl;
        }
    }
}

int main()
{
    Base *p = generate();
    identify_from_pointer(p);
    identify_from_reference(*p);
    return 0;
}