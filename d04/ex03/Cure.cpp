#include <iostream>

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &src) : AMateria(src) {}

Cure &Cure::operator=(const Cure &src)
{
    AMateria::operator=(src);
    return *this;
}

Cure::~Cure() {}

Cure *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << " wounds *" <<std::endl;
    AMateria::use(target);
}