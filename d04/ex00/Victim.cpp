#include <iostream>

#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name)
{
    std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
}

Victim::Victim(const Victim &rhs)
{
    _name = rhs._name;
}

Victim &Victim::operator=(const Victim &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
    }
    return *this;
}

std::string Victim::getName() const
{
    return _name;
}

void Victim::getPolymorphed() const
{
    std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Victim &v)
{
    os << "I'm " << v.getName() << " and I like otters !" << std::endl;
    return os;
}