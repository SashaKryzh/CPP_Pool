#include <iostream>

#include "AWeapon.hpp"
#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(const PowerFist &p) : AWeapon(p) {}

PowerFist &PowerFist::operator=(const PowerFist &p)
{
    if (this != &p)
        AWeapon::operator=(p);
    return *this;
}

PowerFist::~PowerFist() {}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
