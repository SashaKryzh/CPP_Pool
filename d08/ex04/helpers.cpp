#include "ex04.hpp"

void errorExit(std::string message)
{
    std::cout << message << std::endl;
    exit(1);
}

void displayTokens(std::vector<IToken *> tokens)
{
    std::cout << "Tokens:";
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        std::cout << " " << tokens[i]->toString();
    }
    std::cout << std::endl;
}

void displayPostfix(std::queue<IToken *> postfix)
{
    std::cout << "Postfix:";
    while (!postfix.empty())
    {
        std::cout << " " << postfix.front()->toString();
        postfix.pop();
    }
    std::cout << std::endl;
}

void checkParen(std::queue<IToken *> postfix)
{
    while (!postfix.empty())
    {
        if (dynamic_cast<Token<Paren> *> (postfix.front()))
            errorExit("Invalid number of parentheses");
        postfix.pop();
    }
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

std::string stackToString(std::stack<Token<int>*> st)
{
    std::stringstream ss;
    ss << "| ST";
    while (!st.empty())
    {
        ss << " " << st.top()->getValue();
        st.pop();
    }
    ss << "]";
    return ss.str();
}

std::string opDescription(char c)
{
    if (c == '+')
        return "Add";
    if (c == '-')
        return "Substract";
    if (c == '*')
        return "Multiply";
    if (c == '/')
        return "Divide";
    errorExit("How did you do it?!");
    return "";
}