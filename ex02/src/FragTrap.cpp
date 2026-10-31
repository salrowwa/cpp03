#include "../incl/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("NON")
{
	_hit = 100;
	_energy = 100;
	_attack = 30;

	std::cout << "[FragTrap] Default constructor called."
			  << std::endl << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hit = 100;
	_energy = 100;
	_attack = 30;

	std::cout << "[FragTrap] Parameterized constructor called for "
			  << _name << "."
			  << std::endl << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "[FragTrap] Copy constructor called for "
			  << _name << "."
			  << std::endl << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "[FragTrap] Copy assignment operator called."
			  << std::endl << std :: endl;

	if (this != &other)
		ClapTrap::operator=(other);

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] Destructor called."
			  << std::endl << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] " << _name
			  << " raises a hand and asks everyone for a high five!"
			  << std::endl << std::endl;
}