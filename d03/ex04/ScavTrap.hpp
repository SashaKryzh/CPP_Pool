#if !defined(SCAV_TRAP_HPP)
#define SCAV_TRAP_HPP

#include <string>

#include "ClapTrap.hpp"

#define SCAVTRAP "SC4V-TP"

class ScavTrap: public ClapTrap
{
public:
    ScavTrap(std::string name);
    ~ScavTrap();

    ScavTrap(const ScavTrap &f);
	ScavTrap & operator = (const ScavTrap &f);

    void challengeNewcomer(std::string const & target);
};

#endif // FRAG_TRAP_HPP
