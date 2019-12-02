#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// clang++ main.cpp ScavTrap.cpp FragTrap.cpp -Wall -Wextra -Werror

int main()
{
    FragTrap f1("Frag 1");
    FragTrap f2("Frag 2");

    f1.meleeAttack("Your mama");
    f2.rangedAttack("Your papa");

    f1.vaulthunter_dot_exe("Your grandmama");
    f1.vaulthunter_dot_exe("Your grandmama");
    f1.vaulthunter_dot_exe("Your grandmama");
    f1.vaulthunter_dot_exe("Your grandmama");
    f1.vaulthunter_dot_exe("Your grandmama");

    f2.takeDamage(50);
    f2.beRepaired(50);

    f1.takeDamage(1000);

    std::cout << "f3 = f1" << std::endl;

    FragTrap f3 = f1;
    f3.beRepaired(500);
    f3.vaulthunter_dot_exe("Your grandpapa");

    std::cout << std::endl << "START TESTING SCAV" << std::endl << std::endl;

    ScavTrap s1("Scav 1");
    ScavTrap s2("Scav 2");

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

    std::cout << "s3 = s1" << std::endl;

    ScavTrap s3 = s1;
    s3.challengeNewcomer("Your grandpapa");

    return 0;
}