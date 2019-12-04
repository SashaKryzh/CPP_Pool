#if !defined(AWEAPON_HPP)
#define AWEAPON_HPP

#include <string>

class AWeapon
{
private:
    std::string _name;
    int _apcost;
    int _damage;

public:
    AWeapon(std::string const &name, int apcost, int damage);
    AWeapon(const AWeapon &);
    AWeapon &operator=(const AWeapon &);
    ~AWeapon();

    std::string getName() const;
    int getAPCost() const;
    int getDamage() const;

    virtual void attack() const = 0;
};

#endif // AWEAPON_HPP
