#if !defined(SPACE_SHIP_HPP)
#define SPACE_SHIP_HPP

#include "GameEntity.hpp"
#include <string>

class SpaceShip : public GameEntity
{
private:
    int hp_;

public:
    SpaceShip(int hp, t_form form, std::string type, int color);
    virtual ~SpaceShip();

    SpaceShip(const SpaceShip &);
    SpaceShip &operator=(const SpaceShip &);

    int getHP() const;
    bool takeDamage(int damage);
};

#endif // SPACE_SHIP_HPP
