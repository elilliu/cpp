#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon): _name(name), _Weapon(Weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_Weapon.getType() << '\n';
}
