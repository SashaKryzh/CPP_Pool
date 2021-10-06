#ifndef CPOOL_ENEMY_HPP
#define CPOOL_ENEMY_HPP

#include "SpaceShip.hpp"

class Enemy : public SpaceShip
{
private:
public:
    Enemy();
    Enemy(int hp, t_form form, int color);
    ~Enemy();

    Enemy(const Enemy &);
    Enemy &operator=(const Enemy &);

    bool move();
};

#endif
