#if !defined(KOALA_STEROID_HPP)
#define KOALA_STEROID_HPP

#include <string>

#include "IAsteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

class BocalSteroid : public IAsteroid
{
public:
    BocalSteroid();
    BocalSteroid(const BocalSteroid &);
    BocalSteroid &operator=(const BocalSteroid &);
    ~BocalSteroid();

    std::string beMined(DeepCoreMiner *) const;
    std::string beMined(StripMiner *) const;
    std::string getName() const;
};

#endif // KOALA_STEROID_HPP
