#include "Zombie.hpp"

int main()
{
	Zombie *z1= newZombie("z1");
	z1->announce();
	randomChump("z2");
	delete z1;
}