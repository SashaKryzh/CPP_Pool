#include <iostream>

#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &p) : AWeapon(p) {}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &p)
{
    if (this != &p)
        AWeapon::operator=(p);
    return *this;
}

PlasmaRifle::~PlasmaRifle() {}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
