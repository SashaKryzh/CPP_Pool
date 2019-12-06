#include "KoalaSteroid.hpp"

BocalSteroid::BocalSteroid() {}

BocalSteroid::BocalSteroid(const BocalSteroid &) {}

BocalSteroid &BocalSteroid::operator=(const BocalSteroid &)
{
    return *this;
}

BocalSteroid::~BocalSteroid() {}

std::string BocalSteroid::beMined(DeepCoreMiner *) const
{
    return "Zazium";
}

std::string BocalSteroid::beMined(StripMiner *) const
{
    return "Krpite";
}

std::string BocalSteroid::getName() const
{
    return "BocalSteroid";
}
