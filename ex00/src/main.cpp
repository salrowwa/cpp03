#include "../incl/ClapTrap.hpp"

int main()
{
    ClapTrap a("clap");
	a.attack("target");
	a.takeDamage(4);
	a.beRepaired(3);
    
	for (int i = 0; i < 9; i++)
		a.attack("target");

	a.attack("target");
	a.beRepaired(1); 
	a.takeDamage(100);
	a.takeDamage(1);
}