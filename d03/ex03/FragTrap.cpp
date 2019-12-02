#include <iostream>
#include <cmath>

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100,
                                                100, 100, 1, 30,
                                                20, 5)
{
    std::cout << FRAGTRAP << " " << ClapTrap::_name << " is born!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << FRAGTRAP << " " << ClapTrap::_name << " is gone..." << std::endl;
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap(f)
{
    std::cout << FRAGTRAP << " " << ClapTrap::_name << " copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &f)
{
    ClapTrap::operator=(f);
    return *this;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    const int cost = 25;
    const std::string quouts[5] = {
        "This gonna be awesome!",
        "Why am I doing it?",
        "Somebody find me somebody to love!",
        "Here we are with the Princess of the Universe",
        "Is there life on Mars?"};

    if (_ep < cost)
    {
        std::cout << FRAGTRAP << " " << _name << " not enough energy points, have: " << _ep << std::endl;
        return;
    }

    std::cout << FRAGTRAP << " " << _name << " attacks " << target << " with " << quouts[rand() % 5] << std::endl;

    _ep -= cost;
}
