#if !defined(CHARACTER_HPP)
#define CHARACTER_HPP

#include <string>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
private:
    std::string _name;
    int _apPoints;
    AWeapon *_weapon;

public:
    Character(std::string const &name);
    Character(const Character &);
    Character &operator=(const Character &);
    ~Character();
    
    void recoverAP();
    void equip(AWeapon *);
    void attack(Enemy *);
    
    std::string getName() const;
    int getApPoints() const;
    AWeapon *getWeapon() const;
};

std::ostream &operator<<(std::ostream &os, const Character &c);

#endif // CHARACTER_HPP
