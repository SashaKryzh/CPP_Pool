#include <iostream>
#include <cmath>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : _hp(100), _maxHP(100),
                                       _ep(100), _maxEP(100), _level(1), _name(name), _meleeAttackDamage(30),
                                       _rangedAttackDamage(20), _armorDamageReduction(5)
{
    std::cout << SCAVTRAP << " " << _name << " is born!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << SCAVTRAP << " " << _name << " is gone..." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &f)
{
    operator=(f);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &f)
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

void ScavTrap::rangedAttack(std::string const &target)
{
    std::cout << SCAVTRAP << " " << _name << " attacks " << target
              << " at range, causing " << _rangedAttackDamage << " points of damage ranged attack!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
    std::cout << SCAVTRAP << " " << _name << " attacks " << target
              << " at range, causing " << _meleeAttackDamage << " points of damage with melee attack!" << std::endl;
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

void ScavTrap::takeDamage(unsigned int amount)
{
    if (amount > _armorDamageReduction)
        amount -= _armorDamageReduction;
    else
        amount = 0;

    if (_hp > amount)
        _hp -= amount;
    else
        _hp = 0;

    std::cout << SCAVTRAP << " " << _name << " I have took damage, my hp: " << _hp << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    amount = std::min(amount, _maxHP - _hp);

    _hp += amount;

    std::cout << SCAVTRAP << " " << _name << " I have repaired health, my hp: " << _hp << std::endl;
}
