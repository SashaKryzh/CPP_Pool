#if !defined(SCAV_TRAP_HPP)
#define SCAV_TRAP_HPP

#include <string>

#define SCAV_TRAP "<SCAV-TP>"

class ScavTrap
{
public:
    ScavTrap(std::string name);
    ~ScavTrap();

    ScavTrap(const ScavTrap &f);
	ScavTrap & operator = (const ScavTrap &f);

    void rangedAttack(std::string const & target);
    void meleeAttack(std::string const & target);

    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void challengeNewcomer(std::string const & target);

private:
    unsigned int _hp;
    unsigned int _maxHP;
    unsigned int _ep;
    unsigned int _maxEP;
    unsigned int _level;
    std::string _name;
    unsigned int _meleeAttackDamage;
    unsigned int _rangedAttackDamage;
    unsigned int _armorDamageReduction;
};

#endif // FRAG_TRAP_HPP
