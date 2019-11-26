#include <cstdlib>
#include <iostream>

#include "ZombieEvent.hpp"

std::string ZombieEvent::_names[3] = {
	"Gaga",
	"Gogo",
	"Gugu",
};

ZombieEvent::ZombieEvent()
{
	_type = "DefaultType";
}

void ZombieEvent::setZombieType(std::string type)
{
	_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name, _type);
	return zombie;
}

void ZombieEvent::randomChump() const
{
	srand(time(0));
	Zombie zombie = Zombie(_names[rand() % 3], _type);
	zombie.annouce();
}