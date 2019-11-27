#include <iostream>

#include "Fixed.class.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
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

	setRawBits(f.getRawBits());
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
