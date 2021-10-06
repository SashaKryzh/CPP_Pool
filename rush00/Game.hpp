#if !defined(GAME_HPP)
#define GAME_HPP

#include <ncurses.h>
#include <unistd.h>

#include "GameWindow.hpp"
class GameWindow;

#include "Bullet.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "PlayerShip.hpp"

#define STATS_HEIGHT 3

#define MAX_BULLETS 300
#define MAX_ENEMIES 100
#define MAX_PLAYERS 2

class Game
{
private:
    Bullet *bullets_[MAX_BULLETS];
    Enemy *enemies_[MAX_ENEMIES];
    Player *player[MAX_PLAYERS];

    GameWindow &window;

    size_t kills_;

    void addBullet(SpaceShip *);

    void checkColision();
    void checkBulletColisions();

    void deleteBullet(int idx);
    void deleteEnemy(int idx);
    void deletePlayer(int idx);

    void playerDeath(int idx, std::string message);

    void endOfGame(std::string message);

public:
    Game(GameWindow &window);
    ~Game();

    void ketPressed(int key);

    bool playerWantToShoot[2];
    void applyPlayerShoot();

    void enemyShoot();
    void spawnEnemy();

    void movePlayer();
    void moveEnemies();
    void moveBullets();

    void checkCollisions();

    size_t getKillsNb(void) const;
    Player *getPlayer(int idx);

    const Enemy **getEnemies() const;
    const Bullet **getBullets() const;
};

#endif // GAME_HPP
