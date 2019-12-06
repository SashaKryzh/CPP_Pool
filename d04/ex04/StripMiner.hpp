#if !defined(STRIP_MINER_HPP)
#define STRIP_MINER_HPP

#include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser
{
public:
    StripMiner();
    StripMiner(const StripMiner &);
    StripMiner &operator=(const StripMiner &);
    ~StripMiner();

    void mine(IAsteroid *);
    StripMiner *copy() const;
};

#endif // STRIP_MINER_HPP
