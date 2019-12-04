#if !defined(PLASMA_RIFLE_HPP)
#define PLASMA_RIFLE_HPP

#include "PlasmaRifle.hpp"

class PlasmaRifle : public AWeapon
{
private:
public:
    PlasmaRifle();
    PlasmaRifle(const PlasmaRifle &);
    PlasmaRifle &operator=(const PlasmaRifle &);
    ~PlasmaRifle();

    void attack() const;
};

#endif // PLASMA_RIFLE_HPP
