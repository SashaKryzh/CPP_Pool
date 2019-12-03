#if !defined(CLAP_TRAP_HPP)
#define CLAP_TRAP_HPP

#define CLAP_TRAP "CLAP-TP"

class ClapTrap
{
public:
	ClapTrap(std::string name, unsigned int hp,
			 unsigned int maxHP, unsigned int ep,
			 unsigned int maxEP, unsigned int level,
			 unsigned int _meleeDmg,
			 unsigned int rangedDmg,
			 unsigned int armorDmgRed);
	~ClapTrap();

	ClapTrap(const ClapTrap &f);
	ClapTrap &operator=(const ClapTrap &f);

	void rangedAttack(std::string const & target);
    void meleeAttack(std::string const & target);

	void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

	std::string _name;
    unsigned int _hp;
    unsigned int _maxHP;
    unsigned int _ep;
    unsigned int _maxEP;
    unsigned int _level;
    unsigned int _meleeAttackDamage;
    unsigned int _rangedAttackDamage;
    unsigned int _armorDamageReduction;
};

#endif // CLAP_TRAP_HPP
