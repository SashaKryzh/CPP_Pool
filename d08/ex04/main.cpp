#include "ex04.hpp"

int g_token_with = 7;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int parseNum(std::string &s, size_t &i)
{
    int ret;

    try
    {
        ret = std::stoi(&s[i]);
    }
    catch (const std::exception &e)
    {
        errorExit(e.what());
    }

    int numLenght = 0;
    while (isdigit(s[i]))
    {
        numLenght++;
        i++;
    }
    i--;

    if (numLenght + 6 > g_token_with)
        g_token_with = numLenght + 6;
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

    checkParen(postfix);
    return postfix;
}

Token<int> *applyOp(Token<char> *op, Token<int> *n1, Token<int> *n2)
{
    if (op->getValue() == '+')
        return new Token<int>(n1->getValue() + n2->getValue());
    if (op->getValue() == '-')
        return new Token<int>(n1->getValue() - n2->getValue());
    if (op->getValue() == '*')
        return new Token<int>(n1->getValue() * n2->getValue());
    if (op->getValue() == '/')
        return new Token<int>(n1->getValue() / n2->getValue());
    errorExit("How did you do it?!");
    return new Token<int>(-666);
}

int evaluatePostfix(std::queue<IToken *> postfix)
{
    std::stack<Token<int> *> st;

    while (!postfix.empty())
    {
        std::stringstream d;
        d << "I ";

        IToken *token = postfix.front();
        postfix.pop();

        if (dynamic_cast<Token<int> *>(token))
        {
            st.push(dynamic_cast<Token<int> *>(token));
            d << std::setw(g_token_with) << std::left << token->toString();
            d << "| OP " << std::setw(10) << std::left << "Push";
        }

        else
        {
            if (st.size() < 2)
                errorExit("Invalid number of operators");

            Token<int> *num2 = st.top();
            st.pop();
            Token<int> *num1 = st.top();
            st.pop();

            d << std::setw(g_token_with) << std::left << token->toString();
            d << "| OP ";
            d << std::setw(10) << std::left << opDescription(dynamic_cast<Token<char>*>(token)->getValue());
            st.push(applyOp(dynamic_cast<Token<char> *>(token), num1, num2));
        }

        d << stackToString(st);
        std::cout << d.str() << std::endl;
    }

    int ret = st.top()->getValue();
    st.pop();

    if (!st.empty())
        errorExit("Invalid number of ints");

    return ret;
}

int main(int ac, char *av[])
{
    if (ac != 2)
        errorExit("Wrong number of arguments");

    std::vector<IToken *> tokens = parseTokens(av[1]);
    displayTokens(tokens);
    std::queue<IToken *> postfix = toPostfix(tokens);
    displayPostfix(postfix);
    int res = evaluatePostfix(postfix);

    std::cout << "Result : " << res << std::endl;

    return 0;
}