#include <iostream>
#include "Pony.hpp"

Pony::Pony(std::string name) : _name(name)
{
	std::cout << "Hello! I am " << _name << " :)" << std::endl;
}

Pony::~Pony()
{
	std::cout << _name << " had a beautiful life. But now is DEAD." << std::endl;
}

void Pony::howAreYou() {
	std::cout << _name << ": \"I think you are awesome!\"" << std::endl;
}

void ponyOnTheHeap()
{
	Pony* pony = new Pony("HeapPony");
	pony->howAreYou();
	delete pony;
}

void ponyOnTheStack()
{
	Pony pony = Pony("StackPony");
	pony.howAreYou();
}
