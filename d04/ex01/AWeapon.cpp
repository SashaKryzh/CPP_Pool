#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage) {}

AWeapon::AWeapon(const AWeapon &w)
{
    operator=(w);
}

AWeapon &AWeapon::operator=(const AWeapon &w)
{
    if (this != &w)
    {
        _name = w._name;
        _apcost = w._apcost;
        _damage = w._damage;
    }
    return *this;
}

AWeapon::~AWeapon() {}

std::string AWeapon::getName() const
{
    return _name;
}

int AWeapon::getAPCost() const
{
    return _apcost;
}

int AWeapon::getDamage() const
{
    return _damage;
}