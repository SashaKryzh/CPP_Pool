#if !defined(SUPER_ENEMY_HPP)
#define SUPER_ENEMY_HPP

#include "Enemy.hpp"

class SuperEnemy : public Enemy
{
private:
public:
    SuperEnemy();
    ~SuperEnemy();

    SuperEnemy(const SuperEnemy &);
    SuperEnemy &operator=(const SuperEnemy &);
};

#endif // SUPER_ENEMY_HPP
