#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define RESET          "\033[0m"
#define BORDO          "\033[38;5;88m"
#define LILA    		"\033[38;5;103m"
#define BOLD           "\033[1m"

int main()
{
    const int count = 4;
    Animal* animals[count];

    std::cout << BORDO << BOLD << "\n--- 1. ANIMAL ARRAY ---" << RESET << std::endl;
    for (int i = 0; i < count; i++) {
        if (i < count / 2) {
            std::cout <<  LILA << "Creating Dog :" << i << RESET <<std::endl;
            animals[i] = new Dog();
        } else {
            std::cout << LILA << "Creating Cat :" << i << RESET << std::endl;
            animals[i] = new Cat();
        }
    }

    std::cout << BORDO << BOLD << "\n--- 2. SOUND TEST ---" << RESET << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << animals[i]->getType() << " " << i;
        animals[i]->makeSound();
    }

    std::cout << BORDO << BOLD << "\n--- 3. CLEANING UP ---" << RESET << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << LILA << "Deleting Animal " << i << RESET << std::endl;
        delete animals[i];
    }

    std::cout << BORDO << BOLD << "\n--- 4. DEEP COPY TEST ---" << RESET << std::endl;
    {
        std::cout << "Creating Dog and setting ideas" << std::endl;
        Dog dog;
        
		std::cout << "Scope: Creating 'copy' Dog via Copy Constructor."  << std::endl;
		Dog tmp = dog;
		std::cout << "Leaving scope: 'copy' Dog will be destroyed." <<  std::endl;

		std::cout << LILA << BOLD << "Copy Dog destroyed, basic Dog will be destroyed! " << RESET << std::endl;
    }

    return 0;
}