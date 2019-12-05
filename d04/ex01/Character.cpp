#include <iostream>

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _apPoints(40), _weapon(nullptr) {}

Character::Character(const Character &c)
{
    operator=(c);
}

Character &Character::operator=(const Character &c)
{
    if (this != &c)
    {
        _name = c._name;
        _apPoints = c._apPoints;
        _weapon = c._weapon->cloneWeapon();
    }
    return *this;
}

Character::~Character() {}

void Character::recoverAP()
{
    _apPoints = (_apPoints + 10) % 40;
}

void Character::equip(AWeapon *weapon)
{
    _weapon = weapon;
}

void Character::attack(Enemy *e)
{
    if (_weapon != nullptr && e != nullptr)
    {
        if (_apPoints < _weapon->getAPCost())
        {
            std::cout << _name << " not enough AP" << std::endl;
            return ;
        }
        else
            _apPoints -= _weapon->getAPCost();

        std::cout << _name << " attacks " << e->getType() << " with a " << _weapon->getName() << std::endl;
        _weapon->attack();
        e->takeDamage(_weapon->getDamage());
        if (e->getHP() <= 0)
            delete e;
    }
}

std::string Character::getName() const
{
    return _name;
}

int Character::getApPoints() const
{
    return _apPoints;
}

AWeapon *Character::getWeapon() const
{
    return _weapon;
}

std::ostream &operator<<(std::ostream &os, const Character &c)
{
    AWeapon *w = c.getWeapon();

    os << c.getName() << " has " << c.getApPoints() << " AP and ";

    if (w != nullptr)
        os << "wields a " << w->getName();
    else
        os << "is unarmed";

    os << std::endl;
    return os;
}