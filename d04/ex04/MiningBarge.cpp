#include "MiningBarge.hpp"

MiningBarge::MiningBarge()
{
    for (int i = 0; i < 4; i++)
        lasers_[i] = nullptr;
}

MiningBarge::MiningBarge(const MiningBarge &src)
{
    copyLasers(src);
}

MiningBarge &MiningBarge::operator=(const MiningBarge &src)
{
    if (this != &src)
    {
        deleteLasers();
        copyLasers(src);
    }
    return *this;
}

MiningBarge::~MiningBarge()
{
    deleteLasers();
}

void MiningBarge::equip(IMiningLaser *laser)
{
    for (int i = 0; i < 4; i++)
    {
        if (lasers_[i] == nullptr)
        {
            lasers_[i] = laser;
            return;
        }
    }
}

void MiningBarge::mine(IAsteroid *a) const
{
    for (int i = 0; i < 4; i++)
    {
        if (lasers_[i] != nullptr)
            lasers_[i]->mine(a);
    }
}

void MiningBarge::deleteLasers()
{
    for (int i = 0; i < 4; i++)
    {
        if (lasers_[i] != nullptr)
            delete lasers_[i];
    }
}

void MiningBarge::copyLasers(const MiningBarge &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src.lasers_[i] != nullptr)
            lasers_[i] = src.lasers_[i]->copy();
    }
}

