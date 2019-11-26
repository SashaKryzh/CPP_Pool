#ifndef ZOMBIE_EVENT_HPP
#define ZOMBIE_EVENT_HPP

#include <string>

#include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent();

	void setZombieType(std::string type);
	Zombie* newZombie(std::string name);

	void randomChump() const;

private:
	std::string _type;
	static std::string _names[3];
};

#endif