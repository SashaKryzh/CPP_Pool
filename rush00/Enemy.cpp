#include "Enemy.hpp"
#include "Game.hpp"

t_form enemyForm()
{
    t_form form;

    form.lines[0] = " X ";
    form.lines[1] = " X ";
    form.lines[2] = "X X";
    form.cols = 3;
    form.rows = 3;

    return form;
}

int generateX()
{
    int x = rand() % COLS - enemyForm().cols;
    return x < 0 ? 0 : x;
}

Enemy::Enemy() : SpaceShip(100, enemyForm(), ENEMY_T, COLOR_RED)
{
    setPosition(generateX(), STATS_HEIGHT);
}

Enemy::Enemy(int hp, t_form form, int color) : SpaceShip(hp, form, ENEMY_T, color)
{
    setPosition(generateX(), STATS_HEIGHT);
}

Enemy::~Enemy() {}

Enemy::Enemy(const Enemy &src) : SpaceShip(src)
{
    operator=(src);
}

Enemy &Enemy::operator=(const Enemy &src)
{
    if (this != &src)
    {
        SpaceShip::operator=(src);
    }
    return *this;
}

// Return false if coliding border
bool Enemy::move()
{
    return GameEntity::move(0, 1);
}