#if !defined(MINING_BARGE_HPP)
#define MINING_BARGE_HPP

#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"

class MiningBarge
{
private:
    IMiningLaser *lasers_[4];

    void deleteLasers();
    void copyLasers(const MiningBarge &);

public:
    MiningBarge();
    MiningBarge(const MiningBarge &);
    MiningBarge &operator=(const MiningBarge &);
    ~MiningBarge();

    void equip(IMiningLaser *);
    void mine(IAsteroid *) const;
};

#endif // MINING_BARGE_HPP
