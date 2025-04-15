#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "Anonymous";
	this->_type = "ClapTrap";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " has been created.";
	std::cout << " They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_type = "ClapTrap";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " has been created.";
	std::cout << " They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->_name = other._name;
	this->_name += "_v2";
	this->_type = other._type;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "ClapTrap " << this->_name << " has been created.";
	std::cout << " They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_name += "_v2";
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << this->_name << " has been created.\n";
	std::cout << "They have " << this->_hitPoints << " health points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " of attack damage." << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints && this->_hitPoints)
	{
		this->_energyPoints--;
		std::cout << this->_type << " " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage! ";
		std::cout << this->_type << " " << this->_name << " now has " << this->_energyPoints << " energy points." << std::endl;
	}
	else if (!this->_energyPoints)
		std::cout << this->_type << " " << this->_name << " doesn't have enough energy points to attack." << std::endl;
	else
		std::cout << this->_type << " " << this->_name << " is K.O, it can't attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints >= amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << this->_type << " " << this->_name << " takes " << amount << " points of damage! ";
	std::cout << this->_type << " " << this->_name << " now has " << this->_hitPoints << " health points. ";
	if (this->_hitPoints == 0)
		std::cout << this->_type << " " << this->_name << " is K.O.";
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints && this->_energyPoints)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << this->_type << " " << this->_name << " repairs itself with " << amount << " health points. ";
		std::cout << this->_type << " " << this->_name << " now has " << this->_hitPoints << " health points and " << this->_energyPoints << " energy points." << std::endl;
	}
	else if (!this->_energyPoints)
		std::cout << this->_type << " " << this->_name << " doesn't have enough energy points to repair itself." << std::endl;
	else
		std::cout << this->_type << " " << this->_name << " is K.O, it can't be repaired." << std::endl;
}
