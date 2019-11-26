#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human
{
public:
	Human();

	std::string identify() const;
	Brain &getBrain();

private:
	Brain _brain;
};

#endif