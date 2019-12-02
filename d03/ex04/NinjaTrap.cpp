#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name, 60, 60,
												  120, 120, 1, 60,
												  5, 0)
{
	std::cout << NINJATRAP << " " << _name << " is born!" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << NINJATRAP << " " << _name << " is gone..." << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &f) : ClapTrap(f)
{
	std::cout << NINJATRAP << " " << _name << " copy constructor." << std::endl;
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &f)
{
	ClapTrap::operator=(f);
	return *this;
}

void NinjaTrap::ninjaShoebox(ClapTrap &obj)
{
	std::cout << NINJATRAP << " ninjaShoebox:" << std::endl;
	obj.rangedAttack(obj._name);
}

void NinjaTrap::ninjaShoebox(FragTrap &obj)
{
	std::cout << NINJATRAP << " ninjaShoebox:" << std::endl;
	obj.vaulthunter_dot_exe(obj._name);
}

void NinjaTrap::ninjaShoebox(ScavTrap &obj)
{
	std::cout << NINJATRAP << " ninjaShoebox:" << std::endl;
	obj.challengeNewcomer(obj._name);
}

void NinjaTrap::ninjaShoebox(NinjaTrap &obj)
{
	std::cout << NINJATRAP << " ninjaShoebox:" << std::endl;
	std::cout << "There is nothing more to say (" << obj._name << ")" << std::endl;
}
