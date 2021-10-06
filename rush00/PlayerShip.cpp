#include <iostream>

#include "Game.hpp"

#include "PlayerShip.hpp"

t_form playerForm()
{
    t_form form;

    form.lines[0] = " X ";
    form.lines[1] = "XXX";
    form.cols = 3;
    form.rows = 2;

    return form;
}

Player::Player()
    : SpaceShip(100, playerForm(), PLAYER_T, COLOR_GREEN)
{
    setPosition(COLS / 2, LINES - 5);
}

Player::~Player() {}

Player::Player(const Player &src) : SpaceShip(src)
{
    operator=(src);
}

Player &Player::operator=(const Player &src)
{
    if (this != &src)
    {
        SpaceShip::operator=(src);
        nextMove_ = nextMove_;
    }
    return *this;
}

void Player::setNextMove(int x, int y)
{
    nextMove_.x = x;
    nextMove_.y = y;
}

void Player::applyMove()
{
    move(nextMove_.x, nextMove_.y);
    setNextMove(0, 0);
}