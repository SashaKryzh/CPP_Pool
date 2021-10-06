#include "Bullet.hpp"
#include "SpaceShip.hpp"

t_form bulletForm()
{
    t_form form;

    form.lines[0] = ".";
    form.cols = 1;
    form.rows = 1;

    return form;
}

Bullet::Bullet(const SpaceShip *ship, int damage) : GameEntity(bulletForm(), BULLET_T, ship->getColor()), damage_(damage)
{
    t_position shipPos = ship->getPosition();
    t_form form = ship->getForm();

    if (ship->getType() == PLAYER_T)
        moveOnY_ = -1;
    else
        moveOnY_ = 1;

    // x + 1 to center
    size_t y = shipPos.y + (ship->getType() == PLAYER_T ? moveOnY_ : form.rows + moveOnY_);
    setPosition(shipPos.x + 1, y);
}

Bullet::~Bullet() {}

Bullet::Bullet(const Bullet &src) : GameEntity(src)
{
    operator=(src);
}

Bullet &Bullet::operator=(const Bullet &src)
{
    if (this != &src)
    {
        GameEntity::operator=(src);
        moveOnY_ = src.moveOnY_;
        damage_ = src.damage_;
    }
    return *this;
}

// Return false if coliding border
bool Bullet::updateMove()
{
    return move(0, moveOnY_);
}

int Bullet::getDamage() const
{
    return damage_;
}