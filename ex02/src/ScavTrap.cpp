#include "../incl/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("NON")
{
	_hit = 100;
	_energy = 50;
	_attack = 20;

	std::cout << "[ScavTrap] Default constructor called."
			  << std::endl << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hit = 100;
	_energy = 50;
	_attack = 20;

	std::cout << "[ScavTrap] Parameterized constructor called for "
			  << _name << "."
			  << std::endl << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "[ScavTrap] Copy constructor called for "
			  << _name << "."
			  << std::endl << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "[ScavTrap] Copy assignment operator called."
			  << std::endl << std::endl;

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor called."
			  << std::endl << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hit == 0)
	{
		std::cout << "[ScavTrap] " << _name
				  << " has no hit points left and can't attack!"
				  << std::endl << std::endl;
		return;
	}

	else if (_energy == 0)
	{
		std::cout << "[ScavTrap] " << _name
				  << " has run out of energy and can't attack!"
				  << std::endl << std::endl;
		return;
	}

	else
	{
		unsigned int energyBefore = _energy;

		_energy--;

		std::cout << "[ScavTrap] " << _name
				  << " strikes " << target
				  << " and deals " << _attack
				  << " damage!" << std::endl
				  << "Energy:     " << energyBefore << " -> " << _energy
				  << std::endl << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] " << _name
			  << " switches to Gate Keeper mode and holds the line!"
			  << std::endl << std::endl;
}