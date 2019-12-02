#if !defined(NINJA_TRAP_HPP)
#define NINJA_TRAP_HPP

#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#define NINJATRAP "NG4G-TP"

class NinjaTrap: virtual public ClapTrap
{
public:
    NinjaTrap(std::string name);
    ~NinjaTrap();

    NinjaTrap(const NinjaTrap &f);
	NinjaTrap & operator = (const NinjaTrap &f);

	void ninjaShoebox(ClapTrap & target);
	void ninjaShoebox(FragTrap & target);
	void ninjaShoebox(ScavTrap & target);
	void ninjaShoebox(NinjaTrap & target);
};

#endif // NINJA_TRAP_HPP
