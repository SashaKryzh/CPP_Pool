#include "ex04.hpp"

void errorExit(std::string message)
{
    std::cout << message << std::endl;
    exit(1);
}

void displayTokens(std::vector<IToken *> tokens)
{
    std::cout << "Tokens: ";
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        std::cout << " " << tokens[i]->toString();
    }
    std::cout << std::endl;
}

void displayPostfix(std::queue<IToken *> postfix)
{
    std::cout << "Postfix: ";
    while (!postfix.empty())
    {
        std::cout << " " << postfix.front()->toString();
        postfix.pop();
    }
    std::cout << std::endl;
}

int prec(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}