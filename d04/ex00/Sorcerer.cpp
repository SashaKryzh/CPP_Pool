#include <iostream>

#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &rhs)
{
    _name = rhs._name;
    _title = rhs._title;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        _title = rhs._title;
    }
    return *this;
}

std::string Sorcerer::getName() const
{
    return _name;
}

std::string Sorcerer::getTitle() const
{
    return _title;
}

void Sorcerer::polymorph(Victim const &v) const
{
    v.getPolymorphed();
}

std::ostream &operator<<(std::ostream &os, const Sorcerer &sr)
{
    os << "I am " << sr.getName() << ", " << sr.getTitle() << ", and I like ponies !" << std::endl;
    return os;
}