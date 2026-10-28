#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot("Clappy");

    robot.attack("Enemy");
    robot.takeDamage(3);
    robot.beRepaired(2);

    return 0;
}