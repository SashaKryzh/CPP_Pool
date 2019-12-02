#include "FragTrap.hpp"
#include <iostream>

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

    return 0;
}