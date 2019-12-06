#if !defined(DEEP_CORE_MINER_HPP)
#define DEEP_CORE_MINER_HPP

#include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser
{
public:
    DeepCoreMiner();
    DeepCoreMiner(const DeepCoreMiner &);
    DeepCoreMiner &operator=(const DeepCoreMiner &);
    ~DeepCoreMiner();

    void mine(IAsteroid *);
    DeepCoreMiner *copy() const;
};

#endif // DEEP_CORE_MINER_HPP
