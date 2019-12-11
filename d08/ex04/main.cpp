#include "ex04.hpp"

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int parseNum(std::string &s, size_t &i)
{
    (void)s;
    (void)i;
    return 666;
}

std::vector<IToken*> parseTokens(std::string s)
{
    std::vector<IToken*> v;

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
            continue;
        
        else if (isOperator(s[i]))
            v.push_back(new Token<char>(s[i]));

        else if (s[i] == '(' || s[i] == ')')
            v.push_back(new Token<Paren>(Paren(s[i])));

        else if (isdigit(s[i]))
            v.push_back(new Token<int>(parseNum(s, i)));

        else
            errorExit("Unknown character");
    }

    return v;
}

int main(int ac, char *av[])
{
    if (ac != 2)
        errorExit("Wrong number of arguments");

    std::vector<IToken*> tokens = parseTokens(av[1]);

    Token<int> token(43);
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        std::cout << tokens[i]->toString() << " ";
    }

    return 0;
}