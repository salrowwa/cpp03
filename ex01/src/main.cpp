#include "../incl/ScavTrap.hpp"

int main()
{
	std::cout << "===== ClapTrap =====" << std::endl;
	{
		ClapTrap a("clap");
		a.attack("target");
		a.takeDamage(4);
		a.beRepaired(3);
		for (int i = 0; i < 9; i++)      // يخلّص الـ energy
			a.attack("target");
		a.attack("target");              // لازم يفشل (no energy)
		a.beRepaired(1);                 // لازم يفشل
		a.takeDamage(100);               // hit = 0
		a.takeDamage(1);                 // already down
	}

	std::cout << "===== ScavTrap =====" << std::endl;
	{
		ScavTrap s("scav");
		s.attack("target");
		s.takeDamage(30);
		s.beRepaired(10);
		s.guardGate();
	}

	return 0;
}