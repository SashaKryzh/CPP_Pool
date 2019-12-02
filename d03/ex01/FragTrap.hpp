#if !defined(FRAG_TRAP_HPP)
#define FRAG_TRAP_HPP

#include <string>

#define FRAG_TRAP "<FR4G-TP>"

class FragTrap
{
public:
    FragTrap(std::string name);
    ~FragTrap();

    FragTrap(const FragTrap &f);
	FragTrap & operator = (const FragTrap &f);

    void rangedAttack(std::string const & target);
    void meleeAttack(std::string const & target);

    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void vaulthunter_dot_exe(std::string const & target);

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
