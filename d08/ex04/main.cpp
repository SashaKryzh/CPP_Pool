#include "ex04.hpp"

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int parseNum(std::string &s, size_t &i)
{
    int ret = std::stoi(&s[i]);
    while (isdigit(s[i]))
        i++;
    i--;
    return ret;
}

std::vector<IToken *> parseTokens(std::string s)
{
    std::vector<IToken *> v;

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

std::queue<IToken *> toPostfix(std::vector<IToken *> tokens)
{
    std::queue<IToken *> postfix;
    std::stack<IToken *> st;
    std::vector<IToken *>::iterator it;

    for (it = tokens.begin(); it != tokens.end(); ++it)
    {
        if (dynamic_cast<Token<int> *>(*it))
            postfix.push(*it);

        else if (IS_OPEN_PAREN(*it))
            st.push(*it);

        else if (IS_CLOSE_PAREN(*it))
        {
            while (!st.empty() && IS_OPEN_PAREN(st.top()) == false)
            {
                postfix.push(st.top());
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }

        else
        {
            while (!st.empty() && AS_OPER(st.top()) && prec(AS_OPER(*it)->getValue()) <= prec(AS_OPER(st.top())->getValue()))
            {
                postfix.push(st.top());
                st.pop();
            }
            st.push(*it);
        }
    }

    while (!st.empty())
    {
        postfix.push(st.top());
        st.pop();
    }

    return postfix;
}

int main(int ac, char *av[])
{
    if (ac != 2)
        errorExit("Wrong number of arguments");

    std::vector<IToken *> tokens = parseTokens(av[1]);
    displayTokens(tokens);
    std::queue<IToken *> postfix = toPostfix(tokens);
    displayPostfix(postfix);

    return 0;
}