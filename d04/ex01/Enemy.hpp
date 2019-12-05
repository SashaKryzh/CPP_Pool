#if !defined(ENEMY_HPP)
#define ENEMY_HPP

#include <string>

class Enemy
{
private:
    int _hp;
    std::string _type;

public:
    Enemy(int hp, std::string const &type);
    Enemy(const Enemy &);
    Enemy &operator=(const Enemy &);
    virtual ~Enemy();

    std::string getType() const;
    int getHP() const;

    virtual void takeDamage(int);
};

#endif // ENEMY_HPP
