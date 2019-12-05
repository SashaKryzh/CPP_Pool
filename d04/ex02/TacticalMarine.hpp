#if !defined(TACTICAL_MARINE_HPP)
#define TACTICAL_MARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
private:
public:
    TacticalMarine();
    ~TacticalMarine();
    TacticalMarine(const TacticalMarine &);
    TacticalMarine &operator=(const TacticalMarine &);

    ISpaceMarine *clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif // TACTICAL_MARINE_HPP
