#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : ClapTrap(name, 100, 100,
                                                120, 120, 1, 60,
                                                20, 5), FragTrap(name), NinjaTrap(name)
{
    std::cout << SUPER_TRAP << " " << ClapTrap::_name << " is born!" << std::endl;
}

SuperTrap::~SuperTrap()
{
    std::cout << SUPER_TRAP << " " << ClapTrap::_name << " is gone..." << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &f) : ClapTrap(f), FragTrap(f), NinjaTrap(f)
{
    std::cout << SUPER_TRAP << " " << ClapTrap::_name << " copy constructor" << std::endl;
}

SuperTrap &SuperTrap::operator=(const SuperTrap &f)
{
    ClapTrap::operator=(f);
    FragTrap::operator=(f);
    NinjaTrap::operator=(f);
    return *this;
}