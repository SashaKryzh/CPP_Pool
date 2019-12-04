#if !defined(PEON_HPP)
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
public:
    Peon(std::string name);
    ~Peon();
    Peon(const Peon &rhs);
    Peon &operator=(const Peon &rhs);

    void getPolymorphed() const;
};

#endif // PEON_HPP
