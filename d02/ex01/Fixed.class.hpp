#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <ostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	Fixed(const Fixed &f);

	Fixed & operator = (const Fixed &f);
	
	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat() const;
	int toInt() const;

private:
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream& operator<< (std::ostream& stream, const Fixed& f);

#endif