#include "FragTrap.hpp"

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

    return 0;
}