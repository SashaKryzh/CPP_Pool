#include "ZombieEvent.hpp"
#include "Zombie.hpp"

#include <unistd.h>

int main()
{
	ZombieEvent zombieEvent = ZombieEvent();
	Zombie* zombiePtr;

	zombiePtr = zombieEvent.newZombie("First Zombie");
	zombiePtr->annouce();

	zombieEvent.setZombieType("RadioType");
	delete zombiePtr;

	zombiePtr = zombieEvent.newZombie("Second Zombie");
	zombiePtr->annouce();

	zombieEvent.randomChump();
	sleep(1);
	zombieEvent.randomChump();
	sleep(1);
	zombieEvent.randomChump();

	return 0;
}