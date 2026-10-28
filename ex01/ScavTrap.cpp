#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    _HitPoints = 100;
    _Energy = 50;
    _AttackPoints = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _HitPoints = 100;
    _Energy = 50;
    _AttackPoints = 20;
    std::cout << "ScavTrap " << _Name << " parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _Name << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap :: ~ScavTrap()
{
    std::cout << "ScavTrap destructor called"
              << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
    if (_HitPoints == 0 || _Energy == 0)
    {
        std::cout << "ScavTrap " << _Name
                  << " cannot attack!" << std::endl;
        return;
    }

    std::cout << "ScavTrap " << _Name
              << " attacks " << target
              << ", causing " << _AttackPoints
              << " points of damage!" << std::endl;

    _Energy--;
}

void ScavTrap :: guardGate()
{
    std :: cout << "ScavTrap" <<  <<"is now in Gate keeper mode";
}