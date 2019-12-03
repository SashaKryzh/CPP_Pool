#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

// clang++ main.cpp ScavTrap.cpp FragTrap.cpp ClapTrap.cpp NinjaTrap.cpp SuperTrap.cpp -Wall -Wextra -Werror

int main()
{
    FragTrap f1("First");
    // FragTrap f2("Second");

    // f1.meleeAttack("Your mama");
    // f2.rangedAttack("Your papa");

    // f1.vaulthunter_dot_exe("Your grandmama");
    // f1.vaulthunter_dot_exe("Your grandmama");
    // f1.vaulthunter_dot_exe("Your grandmama");
    // f1.vaulthunter_dot_exe("Your grandmama");
    // f1.vaulthunter_dot_exe("Your grandmama");

    // f2.takeDamage(50);
    // f2.beRepaired(50);

    // f1.beRepaired(50);
    // f1.takeDamage(1000);

    // FragTrap f3 = f1;
    // f3.vaulthunter_dot_exe("Your grandpapa");

    // ScavTrap s1("First");
    // ScavTrap s2("Second");

    // s1.meleeAttack("Your mama");
    // s2.rangedAttack("Your papa");

    // s1.challengeNewcomer("Your grandmama");
    // s1.challengeNewcomer("Your grandmama");
    // s1.challengeNewcomer("Your grandmama");
    // s1.challengeNewcomer("Your grandmama");
    // s1.challengeNewcomer("Your grandmama");

    // s2.takeDamage(50);
    // s2.beRepaired(50);

    // s1.beRepaired(50);
    // s1.takeDamage(1000);

    // ScavTrap s3 = s1;
    // s3.challengeNewcomer("Your grandpapa");

    // // NINJA
    // std::cout << std::endl << "NINJA" << std::endl << std::endl;
    // NinjaTrap n1("Ninja 1");
    // NinjaTrap n2("Ninja 2");

    // n1.ninjaShoebox(f1);
    // n1.ninjaShoebox(s1);
    // n2.ninjaShoebox(n2);

    // SUPER
    std::cout << std::endl << "SUPER" << std::endl << std::endl;
    SuperTrap sup1("Super 1");
    SuperTrap sup2("Super 2");
    
    SuperTrap sup3("Super 3");
    sup3 = sup1;

    sup1.ninjaShoebox(f1);
    sup3.vaulthunter_dot_exe("Some target for super");

    return 0;
}