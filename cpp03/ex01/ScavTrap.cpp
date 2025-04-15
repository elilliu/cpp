#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_type = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " has been created.";
	std::cout << " They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_type = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " has been created.";
	std::cout << " They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap " << this->_name << " has been created.";
	std::cout << " They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
