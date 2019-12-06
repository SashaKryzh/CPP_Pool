#if !defined(ICE_HPP)
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
private:
    
public:
    Ice();
    Ice(const Ice &);
    Ice &operator=(const Ice &);
    ~Ice();

    Ice *clone() const;
    void use(ICharacter &target);
};

#endif // ICE_HPP
