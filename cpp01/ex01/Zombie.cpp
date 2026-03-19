#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(): name("unknown"){
	std::cout << name << ": Constructor called\n";
}

Zombie::~Zombie(){
    std::cout << name << ": Destructor called.\n";
}
