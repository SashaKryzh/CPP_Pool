#if !defined(RAD_SCORPIO_HPP)
#define RAD_SCORPIO_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
private:
public:
    RadScorpion();
    RadScorpion(const RadScorpion &);
    RadScorpion &operator=(const RadScorpion &);
    ~RadScorpion();
};


#endif // RAD_SCORPIO_HPP
