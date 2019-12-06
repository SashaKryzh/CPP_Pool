#include "AsteroKreog.hpp"

AsteroBocal::AsteroBocal() {}

AsteroBocal::AsteroBocal(const AsteroBocal &) {}

AsteroBocal &AsteroBocal::operator=(const AsteroBocal &)
{
    return *this;
}

AsteroBocal::~AsteroBocal() {}

std::string AsteroBocal::beMined(DeepCoreMiner *) const
{
    return "Thorite";
}

std::string AsteroBocal::beMined(StripMiner *) const
{
    return "Flavium";
}

std::string AsteroBocal::getName() const
{
    return "AsteroBocal";
}
