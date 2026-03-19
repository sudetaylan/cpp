#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
        Zombie(std::string name) : name(name){
            std::cout << name << ": Constructor called" << std::endl;
        }
		void announce(void);
        ~Zombie(){
            std::cout << name << ": Destructor called." << std::endl;
        }
};

Zombie* newZombie(std::string name);
void randomChump( std::string name );