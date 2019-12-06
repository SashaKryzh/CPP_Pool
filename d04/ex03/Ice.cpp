#include <iostream>

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &src) : AMateria(src) {}

Ice &Ice::operator=(const Ice &src)
{
    AMateria::operator=(src);
    return *this;
}

Ice::~Ice() {}

Ice *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
    AMateria::use(target);
}