#include <limits>
#include <iostream>

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Wrong number of argumens" << std::endl;
        return 0;
    }

    std::string s(av[1]);

    std::cout << "char: ";
    try
    {
        char c = static_cast<char>(std::stoi(av[1], 0, 10));
        if (isprint(c))
            std::cout << c << std::endl;
        else
            std::cout << "Non displayable\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "impossible\n";
    }

    std::cout << "int: ";
    try
    {
        int i = std::stoi(s, 0, 10);
        std::cout << i << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "impossible\n";
    }

    return 0;
}