#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &f);
	Fixed & operator = (const Fixed &f);
	
	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int _value;
	static const int _fractionalBits = 8;
};

#endif