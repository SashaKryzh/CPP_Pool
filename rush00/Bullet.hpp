#if !defined(BULLET_HPP)
#define BULLET_HPP

#include <string>

#include "SpaceShip.hpp"

class Bullet : public GameEntity
{
private:
    int moveOnY_;
    int damage_;

public:
    Bullet(const SpaceShip *, int damage);
    ~Bullet();

    Bullet(const Bullet &);
    Bullet &operator=(const Bullet &);

    bool updateMove();

    int getDamage() const;
};

#endif // BULLET_HPP
