#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    _hit = 100;
    _energy = 50;
    _attack = 20;

    std :: cout << "ScavTrap default constructor called" 
                << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hit = 100;
    _energy = 50;
    _attack = 20;

    std :: cout << "ScavTrap " << _name 
                << " parameterized constructor called" 
                << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std :: cout << "ScavTrap " << _name 
                << " copy constructor called" 
                << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    
    std :: cout << "ScavTrap copy assignment operator called" 
                << std::endl;

    return *this;
}

ScavTrap :: ~ScavTrap()
{
    std :: cout << "ScavTrap destructor called"
              << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hit == 0 || _energy == 0)
    {
        std :: cout << "ScavTrap " << _name
                    << " cannot attack!" 
                    << std::endl;
        return;
    }

    std :: cout << "ScavTrap " << _name
                << " attacks " << target
                << ", causing " << _attack
                << " points of damage!" 
                << std::endl;

    _energy--;
}

void ScavTrap::guardGate()
{
    std :: cout << "ScavTrap " << _name
                << " is now in Gate keeper mode" 
                << std::endl;
}
