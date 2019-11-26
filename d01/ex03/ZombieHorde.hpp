#ifndef ZOMBIE_HORDE_HPP
#define ZOMBIE_HORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int N);
	~ZombieHorde();

	void announce();

private:
	Zombie **_zombies;
	int _zombieCount;

 	static std::string _names[3];
};

#endif