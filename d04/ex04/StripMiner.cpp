#include <iostream>

#include "StripMiner.hpp"

StripMiner::StripMiner() {}

StripMiner::StripMiner(const StripMiner &) {}

StripMiner &StripMiner::operator=(const StripMiner &)
{
    return *this;
}

StripMiner::~StripMiner() {}

void StripMiner::mine(IAsteroid *a)
{
    std::cout << "* strip mining ... got " << a->beMined(this) << " ! *" << std::endl;
}

StripMiner *StripMiner::copy() const
{
    return new StripMiner(*this);
}