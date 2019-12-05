#if !defined(POWER_FIST_HPP)
#define POWER_FIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
private:
public:
    PowerFist();
    PowerFist(const PowerFist &);
    PowerFist &operator=(const PowerFist &);
    ~PowerFist();

    void attack() const;
    PowerFist *cloneWeapon() const;
};

#endif // POWER_FIST_HPP
