#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// clang++ main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp -Wall -Wextra -Werror

int main()
{
    FragTrap f1("First");
    FragTrap f2("Second");

    f1.meleeAttack("Your mama");
    f2.rangedAttack("Your papa");

    f1.vaulthunter_dot_exe("Your grandmama");
    f1.vaulthunter_dot_exe("Your grandmama");
    f1.vaulthunter_dot_exe("Your grandmama");
    f1.vaulthunter_dot_exe("Your grandmama");
    f1.vaulthunter_dot_exe("Your grandmama");

    f2.takeDamage(50);
    f2.beRepaired(50);

    f1.beRepaired(50);
    f1.takeDamage(1000);

    FragTrap f3 = f1;
    f3.vaulthunter_dot_exe("Your grandpapa");

    ScavTrap s1("First");
    ScavTrap s2("Second");

    s1.meleeAttack("Your mama");
    s2.rangedAttack("Your papa");

    s1.challengeNewcomer("Your grandmama");
    s1.challengeNewcomer("Your grandmama");
    s1.challengeNewcomer("Your grandmama");
    s1.challengeNewcomer("Your grandmama");
    s1.challengeNewcomer("Your grandmama");

    s2.takeDamage(50);
    s2.beRepaired(50);

    s1.beRepaired(50);
    s1.takeDamage(1000);

    ScavTrap s3 = s1;
    s3.challengeNewcomer("Your grandpapa");

    return 0;
}