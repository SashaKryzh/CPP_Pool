#if !defined(GAME_ENTITY_HPP)
#define GAME_ENTITY_HPP

#include <string>

#define BULLET_T "bullet"
#define PLAYER_T "player"
#define ENEMY_T "enemy"

typedef struct s_position
{
    int x;
    int y;
} t_position;

typedef struct s_form
{
    std::string lines[3];
    int cols;
    int rows;
} t_form;

class GameEntity
{
private:
    t_position pos_;
    t_position old_;

    t_form form_;
    std::string type_;
    int color_;

public:
    GameEntity(t_form form, std::string type, int color);
    virtual ~GameEntity();

    GameEntity(const GameEntity &);
    GameEntity &operator=(const GameEntity &);

    void setPosition(size_t x, size_t y);

    t_position getPosition() const;
    t_position getOldPosition() const;    
    t_form getForm() const;
    std::string getType() const;
    int getColor() const;

    virtual bool move(int onX, int onY);
    virtual bool move();
    virtual bool isColidingEntity(const GameEntity *) const;
};

#endif // GAME_ENTITY_HPP
