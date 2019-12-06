#if !defined(IMINING_LASER_HPP)
#define IMINING_LASER_HPP

#include "IAsteroid.hpp"

class IAsteroid;

class IMiningLaser
{
public:
    virtual ~IMiningLaser() {}
    virtual void mine(IAsteroid *) = 0;
    virtual IMiningLaser *copy() const = 0;
};

#endif // IMINING_LASER_HPP
