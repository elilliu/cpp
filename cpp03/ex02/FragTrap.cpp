#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_type = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been created.";
	std::cout << " They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_type = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been created.";
	std::cout << " They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "FragTrap " << this->_name << " has been created.";
	std::cout << " They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_name += "_v2";
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "FragTrap " << this->_name << " has been created.\n";
	std::cout << "They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has been destroyed." << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " is waiting for a high five." << std::endl;
}
