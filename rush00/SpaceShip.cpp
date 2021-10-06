#include <iostream>

#include <ncurses.h>
#include "SpaceShip.hpp"

SpaceShip::SpaceShip(int hp, t_form form, std::string type, int color)
    : GameEntity(form, type, color),
      hp_(hp) {}

SpaceShip::~SpaceShip() {}

SpaceShip::SpaceShip(const SpaceShip &src) : GameEntity(src)
{
    operator=(src);
}

SpaceShip &SpaceShip::operator=(const SpaceShip &src)
{
    if (this != &src)
    {
        GameEntity::operator=(src);
        hp_ = src.hp_;
    }
    return *this;
}

int SpaceShip::getHP() const
{
    return hp_;
}

// False if DEAD
bool SpaceShip::takeDamage(int damage)
{
    hp_ -= damage;

    if (hp_ <= 0)
        return false;
    return true;
}
