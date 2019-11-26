#include "ZombieHorde.hpp"
#include "Zombie.hpp"

#include <iostream>

std::string ZombieHorde::_names[3] = {
	"Gaga",
	"Gogo",
	"Gugu",
};

ZombieHorde::ZombieHorde(int N)
{
	_zombies = new Zombie*[N];

	_zombieCount = N;
	for (int i = 0; i < _zombieCount; i++)
	{
		_zombies[i] = new Zombie(_names[rand() % 3], "ZombieType");
	}
}

ZombieHorde::~ZombieHorde()
{
	for (int i = 0; i < _zombieCount; i++)
	{
		delete _zombies[i];
	}
	delete _zombies;
}

void ZombieHorde::announce()
{
	for (int i = 0; i < _zombieCount; i++)
	{
		_zombies[i]->annouce();
	}
}