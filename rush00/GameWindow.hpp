#if !defined(GAME_WINDOW_HPP)
#define GAME_WINDOW_HPP

#include <ncurses.h>

#define statsWinHeight = 3

#include "Bullet.hpp"
#include "PlayerShip.hpp"
#include "Enemy.hpp"
#include "Game.hpp"

class Game;

extern int NUM_PLAYER;

class GameWindow
{
private:
    WINDOW *statsWin;

    char **background_;

    void drawEnemies(const Enemy *[]);
    void drawBullets(const Bullet *[]);

    void drawObject(const GameEntity *obj);

public:
    GameWindow();
    ~GameWindow();

    void undrawObject(const GameEntity *);

    void drawStats(Game &);
    void refreshWin(Game &);

    void refreshBackground();

    void endOfGame(std::string message);

    void deinit();
};

#endif // GAME_WINDOW_HPP
