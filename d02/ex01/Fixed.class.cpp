#include <iostream>
#include <cmath>

#include "Fixed.class.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

	_value = (int)roundf((value * (1 << _fractionalBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;

	operator=(f);
}

Fixed & Fixed::operator=(const Fixed &f)
{
	std::cout << "Assignation operator called" << std::endl;

	_value = f._value;
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;

	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat() const
{
	return _value / (float)(1 << _fractionalBits);
}

int Fixed::toInt() const
{
	return _value >> _fractionalBits;
}

std::ostream & operator<< (std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}