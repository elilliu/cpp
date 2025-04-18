#include "Brain.hpp"

Brain::Brain(){
	std::cout << "A brain has beed created.\n";
}

Brain::Brain(const Brain& copy){
	*this = copy;
	std::cout << "A brain has been copied by copying another brain.\n";
}

Brain&	Brain::operator=(const Brain& copy){
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	std::cout << "A brain has been copied via copy operator.\n";
	return (*this);
}

Brain::~Brain(){
	std::cout << "A brain has been destroyed.\n";
}


