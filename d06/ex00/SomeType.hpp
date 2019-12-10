#if !defined(SOME_TYPE_HPP)
#define SOME_TYPE_HPP

#include <string>

class SomeType
{
private:
    std::string _value;

public:
    SomeType(std::string s);
    ~SomeType();

    SomeType(SomeType &);
    SomeType &operator=(SomeType const &);

    operator char(void) const;
    operator int(void) const;
    operator float(void) const;
    operator double(void) const;

    struct BadConversion : public std::exception
    {
        const char *what() const throw();
    };

    struct NonDisplayable : public std::exception
    {
        const char *what() const throw();
    };
};

#endif // SOME_TYPE_HPP
