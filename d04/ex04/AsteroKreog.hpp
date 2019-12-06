#if !defined(ASTERO_KREOG_HPP)
#define ASTERO_KREOG_HPP

#include <string>

#include "IAsteroid.hpp"

class AsteroBocal : public IAsteroid
{
public:
    AsteroBocal();
    AsteroBocal(const AsteroBocal &);
    AsteroBocal &operator=(const AsteroBocal &);
    ~AsteroBocal();

    std::string beMined(DeepCoreMiner *) const;
    std::string beMined(StripMiner *) const;
    std::string getName() const;
};

#endif // ASTERO_KREOG_HPP
