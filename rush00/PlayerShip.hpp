#if !defined(PLAYER_SHIP)
#define PLAYER_SHIP

#include <string>

#include "SpaceShip.hpp"

class Player : public SpaceShip
{
private:
    t_position nextMove_;

public:
    Player();
    ~Player();

    Player(const Player &);
    Player &operator=(const Player &);

    void setNextMove(int x, int y);
    void applyMove();
};

#endif // PLAYER_SHIP
