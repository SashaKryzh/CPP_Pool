#include <ncurses.h>

#include "Game.hpp"
#include "GameWindow.hpp"

#include "PlayerShip.hpp"

int NUM_PLAYER = -1;

int main()
{
    // Initialize only in this order!
    GameWindow window;
    Game game(window);
    /////////////////////////////////

    int tick = 0;

    while (true)
    {
        int key = getch();
        if (key == 27)
            break;

        game.ketPressed(key);

        if (tick % 40 == 0)
        {
            game.applyPlayerShoot();
            game.moveBullets();
        }

        // Move out player
        if (tick % 60 == 0)
        {
            game.movePlayer();
        }

        if (tick % 1000 == 0)
        {
            game.moveEnemies();
            game.spawnEnemy();
        }

        if (tick % 1500 == 0)
        {
            game.enemyShoot();
        }

        if (tick % 200 == 0)
        {
            window.refreshBackground();
        }

        game.checkCollisions();
        window.refreshWin(game);

        tick++;
        tick %= 10000;
        usleep(1000);
    }

    window.deinit();
    return (0);
}
