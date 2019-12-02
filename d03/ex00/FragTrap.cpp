#include <iostream>
#include <cmath>

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : _hp(100), _maxHP(100),
                                       _ep(100), _maxEP(100), _level(1), _name(name), _meleeAttackDamage(30),
                                       _rangedAttackDamage(20), _armorDamageReduction(5)
{
    std::cout << FRAGTRAP << " " << _name << " is born!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << FRAGTRAP << " " << _name << " is gone..." << std::endl;
}

FragTrap::FragTrap(const FragTrap &f)
{
    operator=(f);
}

FragTrap &FragTrap::operator=(const FragTrap &f)
{
    _hp = f._hp;
    _maxHP = f._maxHP;
    _ep = f._ep;
    _maxEP = f._maxEP;
    _level = f._level;
    _name = f._name;
    _meleeAttackDamage = f._meleeAttackDamage;
    _rangedAttackDamage = f._rangedAttackDamage;
    _armorDamageReduction = f._armorDamageReduction;
    return *this;
}

void FragTrap::rangedAttack(std::string const &target)
{
    std::cout << FRAGTRAP << " " << _name << " attacks " << target
              << " at range, causing " << _rangedAttackDamage << " points of damage ranged attack!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
    std::cout << FRAGTRAP << " " << _name << " attacks " << target
              << " at range, causing " << _meleeAttackDamage << " points of damage with melee attack!" << std::endl;
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

void FragTrap::takeDamage(unsigned int amount)
{
    if (amount > _armorDamageReduction)
        amount -= _armorDamageReduction;
    else
        amount = 0;

    if (_hp > amount)
        _hp -= amount;
    else
        _hp = 0;

    std::cout << FRAGTRAP << " " << _name << " I have took damage, my hp: " << _hp << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    amount = std::min(amount, _maxHP - _hp);

    _hp += amount;

    std::cout << FRAGTRAP << " " << _name << " I have repaired health, my hp: " << _hp << std::endl;
}
