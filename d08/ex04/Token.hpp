#if !defined(TOKEN_HPP)
#define TOKEN_HPP

#include <ostream>

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
    Token(T value);
    ~Token();

    Token(const Token<T> &);
    Token &operator=(const Token<T> &);

    T getValue() const;
    std::string toString() const;
};

#include "Token.ipp"

// std::ostream &operator<<(std::ostream &os, const Token<char> &dt);
// std::ostream &operator<<(std::ostream &os, const Token<int> &dt);
// std::ostream &operator<<(std::ostream &os, const Token<Paren> &dt);

#endif // TOKEN_HPP
