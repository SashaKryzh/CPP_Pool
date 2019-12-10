#include "SomeType.hpp"

SomeType::SomeType(std::string s) : _value(s) {}

SomeType::~SomeType() {}

SomeType::SomeType(SomeType &src)
{
    operator=(src);
}

SomeType &SomeType::operator=(SomeType const &src)
{
    if (this != &src)
    {
        _value = src._value;
    }
    return *this;
}

SomeType::operator char(void) const
{
    try
    {
        char c = static_cast<char>(std::stoi(_value));
        if (isprint(c))
            return c;
        else
            throw NonDisplayable();
    }
    catch (const NonDisplayable &e)
    {
        throw e;
    }
    catch (const std::exception &e)
    {
        throw BadConversion();
    }
}

SomeType::operator int(void) const
{
    try
    {
        return std::stoi(_value);
    }
    catch (const std::exception &e)
    {
        throw BadConversion();
    }
}

SomeType::operator float(void) const
{
    try
    {
        return std::stof(_value);
    }
    catch (const std::exception &e)
    {
        throw BadConversion();
    }
}

SomeType::operator double(void) const
{
    try
    {
        return std::stod(_value);
    }
    catch (const std::exception &e)
    {
        throw BadConversion();
    }
}

const char *SomeType::BadConversion::what() const throw()
{
    return "impossible";
}

const char *SomeType::NonDisplayable::what() const throw()
{
    return "Non displayable";
}