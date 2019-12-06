#if !defined(AMATERIA_HPP)
#define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
    unsigned int xp_;
    std::string type_;

public:
    AMateria(std::string const &type);
    AMateria(const AMateria &);
    AMateria &operator=(const AMateria &);
    virtual ~AMateria();

    std::string const &getType() const; //Returns the materia type
    unsigned int getXP() const;         //Returns the Materia's XP

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif // AMATERIA_HPP
