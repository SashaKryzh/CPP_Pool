#if !defined(FRAG_TRAP_HPP)
#define FRAG_TRAP_HPP

#include <string>

#include "ClapTrap.hpp"

#define FRAGTRAP "FR4G-TP"

class FragTrap: virtual public ClapTrap
{
public:
    FragTrap(std::string name);
    ~FragTrap();

    FragTrap(const FragTrap &f);
	FragTrap & operator = (const FragTrap &f);

    void vaulthunter_dot_exe(std::string const & target);
};

#endif // FRAG_TRAP_HPP
