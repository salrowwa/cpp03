#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
    if (_hit == 0 || _energy == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot attack!" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attack
              << " points of damage!" << std::endl;

    _energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " has no hit points left!" 
                  << std::endl;
        return;
    }

    if (amount >= _hit)
        _hit = 0;
    else
        _hit -= amount;

    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage!" 
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy == 0 || _hit == 0)
	{
		std::cout << "ClapTrap " << _name 
                  << " can't repair itself because it's out of energy or hit points." 
                  << std::endl;
		return;
	}

	_hit += amount;
	--_energy;

	std::cout << "ClapTrap " << _name
              << " repairs itself, regaining " 
              << amount << " hit points!" 
              << std::endl;
}

ClapTrap :: ClapTrap () : _name("Default"), _hit(10), _energy(10), _attack(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap :: ClapTrap(const std::string & name) 
            : _name(name), _hit(10), _energy(10), _attack(0)
{
      std::cout << "ClapTrap " << _name
                << " parameterized constructor called" 
                << std::endl;
}

ClapTrap :: ClapTrap(const ClapTrap& other) 
            : _name(other._name), _hit(other._hit),
              _energy(other._energy), _attack(other._attack)
{
    std::cout << "ClapTrap " << _name << " copy constructor called" 
              << std::endl;
}

ClapTrap& ClapTrap :: operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hit = other._hit;
        _attack = other._attack;
        _energy = other._energy;

    }

    return (*this);
}

ClapTrap :: ~ClapTrap()
{
    std::cout << "ClapTrap destructor called"
              << std::endl;
}
