#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : xp_(0), type_(type) {}

AMateria::AMateria(const AMateria &src)
{
    xp_ = src.xp_;
    type_ = src.type_;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    if (this != &src)
    {
        xp_ = src.xp_;
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
    return type_;
}

unsigned int AMateria::getXP() const
{
    return xp_;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
    xp_ += 10;
}