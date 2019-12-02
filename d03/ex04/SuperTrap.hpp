#if !defined(SUPER_TRAP_HPP)
#define SUPER_TRAP_HPP

#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

#define SUPER_TRAP "SUPER-TP"

class SuperTrap: virtual public FragTrap, virtual public NinjaTrap 
{
public:
    SuperTrap(std::string name);
    ~SuperTrap();

    SuperTrap(const SuperTrap &f);
	SuperTrap & operator = (const SuperTrap &f);
};

#endif // SUPER_TRAP_HPP
