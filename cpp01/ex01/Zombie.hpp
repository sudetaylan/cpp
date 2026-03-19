#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
        Zombie();
		void announce(void);
		void setName(std::string name);
        ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);
