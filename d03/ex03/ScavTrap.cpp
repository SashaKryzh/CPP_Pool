#include <iostream>
#include <cmath>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 100,
                                                100, 100, 1, 30,
                                                20, 5)
{
    std::cout << SCAVTRAP << " " << _name << " is born!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << SCAVTRAP << " " << _name << " is gone..." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &f) : ClapTrap(f)
{
    std::cout << SCAVTRAP << " " << _name << " copy constructor." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &f)
{
    ClapTrap::operator=(f);
    return *this;
}

void ScavTrap::challengeNewcomer(std::string const &target)
{
    const std::string challenges[5] = {
        "I bet you would not jump off the roof!",
        "I bet you would not say Fuck to your mom!",
        "I am sure that you could not jump more than 5 times in a row",
        "You could not breathe and sneeze at the same time,",
        "I am sure you would not change your gender...",
    };

    std::cout << SCAVTRAP << " " << _name << " challenges " << target << " with " << challenges[rand() % 5] << std::endl;
}
