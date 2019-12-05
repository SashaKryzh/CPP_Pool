#include <iostream>

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &s) : Enemy(s) {}

RadScorpion &RadScorpion::operator=(const RadScorpion &s)
{
    Enemy::operator=(s);
    return *this;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}