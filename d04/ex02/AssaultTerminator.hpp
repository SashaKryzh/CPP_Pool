#if !defined(ASSAULT_TERMINATOR_HPP)
#define ASSAULT_TERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
private:
public:
    AssaultTerminator();
    ~AssaultTerminator();
    AssaultTerminator(const AssaultTerminator &);
    AssaultTerminator &operator=(const AssaultTerminator &);

    ISpaceMarine *clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif // ASSAULT_TERMINATOR_HPP
