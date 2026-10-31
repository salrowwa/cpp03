#include "../incl/ScavTrap.hpp"
#include "../incl/FragTrap.hpp"

int main()
{
	std::cout << "===== ClapTrap =====" << std::endl;
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

	std::cout << "===== ScavTrap =====" << std::endl;
	{
		ScavTrap s("scav");
		s.attack("target");
		s.takeDamage(30);
		s.beRepaired(10);
		s.guardGate();
	}

	std::cout << "===== FragTrap =====" << std::endl;
	{
		FragTrap f("frag");
		f.attack("target");
		f.takeDamage(5);
		f.beRepaired(2);
		f.highFivesGuys();
	}

	std::cout << "===== Copy =====" << std::endl;
	{
		FragTrap f1("original");
		FragTrap f2(f1);
		FragTrap f3;
		f3 = f1;
	}
	return 0;
}