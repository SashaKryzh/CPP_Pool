#if !defined(CURE_HPP)
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
private:
    
public:
    Cure();
    Cure(const Cure &);
    Cure &operator=(const Cure &);
    ~Cure();

    Cure *clone() const;
    void use(ICharacter &target);
};

#endif // CURE_HPP
