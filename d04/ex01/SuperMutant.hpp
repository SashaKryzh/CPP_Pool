#if !defined(SUPER_MUTANT_HPP)
#define SUPER_MUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
private:
public:
    SuperMutant();
    SuperMutant(const SuperMutant &);
    SuperMutant &operator=(const SuperMutant &);
    ~SuperMutant();

    void takeDamage(int);
};

#endif // SUPER_MUTANT_HPP
