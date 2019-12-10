#include <limits>
#include <iostream>

#include "SomeType.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Wrong number of argumens" << std::endl;
        return 0;
    }

    SomeType type(av[1]);

    std::cout << "char: ";
    try
    {
        std::cout << static_cast<char>(type) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "int: ";
    try
    {
        std::cout << static_cast<int>(type) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "float: ";
    try
    {
        std::cout << static_cast<float>(type) << "f" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "double: ";
    try
    {
        std::cout << static_cast<double>(type) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}