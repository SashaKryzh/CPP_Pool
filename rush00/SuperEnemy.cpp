#include "SuperEnemy.hpp"
#include "Game.hpp"

t_form superEnemyForm()
{
    t_form form;

    form.lines[0] = "XXX";
    form.lines[1] = "XXX";
    form.lines[2] = "X X";
    form.cols = 3;
    form.rows = 3;

    return form;
}

SuperEnemy::SuperEnemy() : Enemy(1000, superEnemyForm(), COLOR_MAGENTA) {}

SuperEnemy::~SuperEnemy() {}

SuperEnemy::SuperEnemy(const SuperEnemy &src) : Enemy(src)
{
    operator=(src);
}

SuperEnemy &SuperEnemy::operator=(const SuperEnemy &src)
{
    if (this != &src)
    {
        Enemy::operator=(src);
    }
    return *this;
}