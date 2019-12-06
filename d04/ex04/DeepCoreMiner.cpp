#include <iostream>

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner() {}

DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner &) {}

DeepCoreMiner &DeepCoreMiner::operator=(const DeepCoreMiner &)
{
    return *this;
}

DeepCoreMiner::~DeepCoreMiner() {}

void DeepCoreMiner::mine(IAsteroid *a)
{
    std::cout << "* mining deep ... got " << a->beMined(this) << " ! *" << std::endl;
}

DeepCoreMiner *DeepCoreMiner::copy() const
{
    return new DeepCoreMiner(*this);
}