#include <iostream>

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &s) : Enemy(s) {}

SuperMutant &SuperMutant::operator=(const SuperMutant &s)
{
    Enemy::operator=(s);
    return *this;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    Enemy::takeDamage(damage - 3);
}