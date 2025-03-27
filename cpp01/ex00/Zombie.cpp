#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    this->announce();
}

Zombie::~Zombie()
{
    std::cout << this->_name << " has been destroyed x_x\n";
}

void    Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
