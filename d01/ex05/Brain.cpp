#include "Brain.hpp"
#include <iostream>
#include <sstream>

std::string Brain::identify() const
{
	std::stringstream ss;
	ss << (void const *)this;  
	return ss.str(); 
}