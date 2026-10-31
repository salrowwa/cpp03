#include "../incl/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("NON"), _hit(10), _energy(10), _attack(0)
{
	std::cout << "[ClapTrap] Default constructor called."
			  << std::endl << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hit(10), _energy(10), _attack(0)
{
	std::cout << "[ClapTrap] Parameterized constructor called for "
			  << _name << "."
			  << std::endl << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hit(other._hit),
	  _energy(other._energy), _attack(other._attack)
{
	std::cout << "[ClapTrap] Copy constructor called for "
			  << _name << "."
			  << std::endl << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "[ClapTrap] Copy assignment operator called."
			  << std::endl << std::endl;

	if (this != &other)
	{
		_name = other._name;
		_hit = other._hit;
		_attack = other._attack;
		_energy = other._energy;
	}

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] Destructor called."
			  << std::endl << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hit == 0)
	{
		std::cout << "[ClapTrap] " << _name
				  << " is out of hit points and can't attack!"
				  << std::endl << std::endl;

		return;
	}

	else if (_energy == 0)
	{
		std::cout << "[ClapTrap] " << _name
				  << " is out of energy and can't attack!"
				  << std::endl << std::endl;
		return;
	}

	else
	{
		unsigned int energyBefore = _energy;

		_energy--;

		std::cout << "[ClapTrap] " << _name
				  << " strikes " << target
				  << " and deals " << _attack
				  << " damage!" << std::endl
				  << "Energy:     " << energyBefore << " -> " << _energy
				  << std::endl << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit == 0)
	{
		std::cout << "[ClapTrap] " << _name
				  << " is already down, no hit points left!"
				  << std::endl << std::endl;
		return;
	}

	unsigned int hitBefore = _hit;

	if (amount >= _hit)
		_hit = 0;
	else
		_hit -= amount;

	std::cout << "[ClapTrap] " << _name
			  << " gets hit and loses " << amount
			  << " hit points!" << std::endl
			  << "Hit points: " << hitBefore << " -> " << _hit
			  << std::endl << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy == 0 || _hit == 0)
	{
		std::cout << "[ClapTrap] " << _name
				  << " can't repair: no energy or hit points left."
				  << std::endl << std::endl;
		return;
	}

	unsigned int hitBefore = _hit;
	unsigned int energyBefore = _energy;

	_hit += amount;
	--_energy;

	std::cout << "[ClapTrap] " << _name
			  << " patches itself up and recovers "
			  << amount << " hit points!" << std::endl
			  << "Hit points: " << hitBefore << " -> " << _hit << std::endl
			  << "Energy:     " << energyBefore << " -> " << _energy
			  << std::endl << std::endl;
}