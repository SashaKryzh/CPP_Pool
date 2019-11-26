#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {}

void Zombie::annouce() const
{
	std::cout << "<"
	<< _name
	<< " ("
	<< _type
	<< ")> Braiiiiiiinnnssss..."
	<< std::endl;
}