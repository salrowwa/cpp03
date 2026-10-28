#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
    if (_HitPoints == 0 || _Energy == 0)
    {
        std::cout << "ClapTrap " << _Name
                  << " cannot attack!" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << _Name
              << " attacks " << target
              << ", causing " << _AttackPoints
              << " points of damage!" << std::endl;

    _Energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_HitPoints == 0)
    {
        std::cout << "ClapTrap " << _Name
                  << " has no hit points left!" << std::endl;
        return;
    }

    if (amount >= _HitPoints)
        _HitPoints = 0;
    else
        _HitPoints -= amount;

    std::cout << "ClapTrap " << _Name
              << " takes " << amount
              << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_Energy == 0 || _HitPoints == 0)
	{
		std::cout << "ClapTrap " << _Name 
                  << " can't repair itself because it's out of energy or hit points." 
                  << std::endl;
		return;
	}

	_HitPoints += amount;
	--_Energy;

	std::cout << "ClapTrap " << _Name
              << " repairs itself, regaining " 
              << amount << " hit points!" 
              << std::endl;
}

ClapTrap :: ClapTrap () : _Name("Default"), _HitPoints(10), _Energy(10), _AttackPoints(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap :: ClapTrap(const std::string & name) : 
                _Name( name), _HitPoints(10), _Energy(10), _AttackPoints(0)
{
      std::cout << "ClapTrap " << _Name
              << " parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _Name(other._Name), _HitPoints(other._HitPoints),
      _Energy(other._Energy), _AttackPoints(other._AttackPoints)
{
    std::cout << "ClapTrap " << _Name << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap :: operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _Name = other._Name;
        _HitPoints = other._HitPoints;
        _AttackPoints = other._AttackPoints;
        _Energy = other._Energy;

    }

    return (*this);
}

ClapTrap :: ~ClapTrap()
{
    std::cout << "ClapTrap destructor called"
              << std::endl;
}
