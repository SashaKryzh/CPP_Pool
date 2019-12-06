#include "MiningBarge.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "KoalaSteroid.hpp"
#include "AsteroKreog.hpp"

#include <iostream>

int main()
{
    std::cout << "barge\n";

    MiningBarge barge;

    barge.equip(new DeepCoreMiner());
    barge.equip(new StripMiner());

    IAsteroid *asteroBocal = new AsteroBocal();
    IAsteroid *bocalSteroid = new BocalSteroid();

    barge.mine(asteroBocal);
    barge.mine(bocalSteroid);

    std::cout << "\nbarge2\n";

    MiningBarge barge2;
    barge2 = barge;

    barge2.equip(new DeepCoreMiner());
    barge2.equip(new DeepCoreMiner());
    barge2.equip(new DeepCoreMiner());
    
    barge2.mine(bocalSteroid);

    std::cout << "\nbarge3\n";

    MiningBarge barge3(barge2);

    barge3.mine(asteroBocal);

    return 0;
}