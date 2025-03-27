#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie(){
    std::cout << this->_name << " has been destroyed x_x\n";
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void    Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
