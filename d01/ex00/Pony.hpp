#ifndef PONY_HPP
#define PONY_HPP

#include <string>

#include "Pony.hpp"

class Pony
{
public:
	Pony(std::string name);
	~Pony(void);

	void howAreYou(void);

private:
	std::string _name;
};

void ponyOnTheHeap(void);
void ponyOnTheStack(void);

#endif