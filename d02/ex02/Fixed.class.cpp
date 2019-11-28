#include <iostream>
#include <cmath>

#include "Fixed.class.hpp"

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;

	_value = (int)roundf((value * (1 << _fractionalBits)));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	// std::cout << "Copy constructor called" << std::endl;

	operator=(f);
}

// Operators -----
Fixed &Fixed::operator=(const Fixed &f)
{
	// std::cout << "Assignation operator called" << std::endl;

	_value = f._value;
	return *this;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return _value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return _value < rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return _value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return _value <= rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return _value == rhs._value;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return _value != rhs._value;
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed ret;
	ret.setRawBits(_value + rhs._value);
	return ret;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed ret;
	ret.setRawBits(_value - rhs._value);
	return ret;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed ret;
	signed int c = _value * rhs._value;

	if (c / rhs._value != _value)
	{
		// Overflow!
		signed int i1 = _value / DIGITS;
		signed int i2 = rhs._value / DIGITS;
		signed int f1 = (_value & (DIGITS - 1));
		signed int f2 = (rhs._value & (DIGITS - 1));
		ret.setRawBits((i1 * i2) * DIGITS + (f1 * f2) / DIGITS + i1 * f2 + i2 * f1);
	}
	else
	{
		ret.setRawBits(c / DIGITS);
	}

	return ret;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed ret;

	if (_value > (1 << 21))
	{
		// Overflow!
		signed int i = _value / DIGITS;
		signed int f = (_value & (DIGITS - 1));
		ret.setRawBits(((i * DIGITS) / rhs._value) * DIGITS + (f * DIGITS) / rhs._value);
	}
	else
	{
		ret.setRawBits((_value * DIGITS) / rhs._value);
	}

	return ret;
}

Fixed &Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed &Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_value++;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_value--;
	return tmp;
}

// Methods ------
int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;

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

// Static ------
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

// Stream ------
std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}