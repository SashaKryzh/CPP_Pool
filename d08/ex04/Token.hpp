#if !defined(TOKEN_HPP)
#define TOKEN_HPP

#include <sstream>

#define IS_OPEN_PAREN(x) (dynamic_cast<Token<Paren>*>(x) && dynamic_cast<Token<Paren>*>(x)->getValue()._c == '(')
#define IS_CLOSE_PAREN(x) (dynamic_cast<Token<Paren>*>(x) && dynamic_cast<Token<Paren>*>(x)->getValue()._c == ')')

#define AS_OPER(x) (dynamic_cast<Token<char>*>(x))

class IToken
{
public:
    virtual ~IToken(){};
    virtual std::string toString() const = 0;
};

struct Paren
{
    char _c;
    Paren(char c);
};

template <typename T>
class Token : public IToken
{
private:
    T _value;

public:
    Token(T value) : _value(value) {}
    ~Token() {}

    Token(const Token<T> &src) { operator=(src); }
    Token &operator=(const Token<T> &src)
    {
        if (this != &src)
        {
            _value = src._src;
        }
        return *this;
    }

    T getValue() const { return _value; }
    std::string toString() const { return "hz"; }
};

// template <>
// inline std::string Token<char>::getType() const
// {
//     return "op";
// }

// template <>
// inline std::string Token<int>::getType() const
// {
//     return "num";
// }

// template <>
// inline std::string Token<Paren>::getType() const
// {
//     return "paren";
// }

template <>
inline std::string Token<char>::toString() const
{
    std::stringstream ss;
    ss << "Op(" << _value << ")";
    return ss.str();
}

template <>
inline std::string Token<int>::toString() const
{
    std::stringstream ss;
    ss << "Num(" << _value << ")";
    return ss.str();
}

template <>
inline std::string Token<Paren>::toString() const
{
    if (_value._c == '(')
        return "ParOpen";
    else
        return "ParClose";
}

#endif // TOKEN_HPP
