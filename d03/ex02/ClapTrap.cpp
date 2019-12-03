#include <string>
#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, unsigned int hp,
				   unsigned int maxHP, unsigned int ep,
				   unsigned int maxEP, unsigned int level,
				   unsigned int meleeDmg,
				   unsigned int rangedDmg,
				   unsigned int armorDmgRed) : _name(name), _hp(hp),
											   _maxHP(maxHP), _ep(ep), _maxEP(maxEP), _level(level),
											   _meleeAttackDamage(meleeDmg),
											   _rangedAttackDamage(rangedDmg),
											   _armorDamageReduction(armorDmgRed)
{
	std::cout << CLAP_TRAP << " unit is constructed with name: " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << CLAP_TRAP << " unit is destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &f)
{
	operator=(f);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &f)
{
	_name = f._name;
	_hp = f._hp;
	_maxHP = f._maxHP;
	_ep = f._ep;
	_maxEP = f._maxEP;
	_level = f._level;
	_meleeAttackDamage = f._meleeAttackDamage;
	_rangedAttackDamage = f._rangedAttackDamage;
	_armorDamageReduction = f._armorDamageReduction;
	return *this;
}

void ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << CLAP_TRAP << " " << _name << " attacks " << target
              << " at range, causing " << _rangedAttackDamage << " points of damage ranged attack!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << CLAP_TRAP << " " << _name << " attacks " << target
              << " at range, causing " << _meleeAttackDamage << " points of damage with melee attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _armorDamageReduction)
        amount -= _armorDamageReduction;
    else
        amount = 0;

    if (_hp > amount)
        _hp -= amount;
    else
        _hp = 0;

    std::cout << CLAP_TRAP << " " << _name << " I have took damage, my hp: " << _hp << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	amount = std::min(amount, _maxHP - _hp);

    _hp += amount;

    std::cout << CLAP_TRAP << " " << _name << " I have repaired health, my hp: " << _hp << std::endl;
}