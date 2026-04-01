#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

#define BLUE_BOLD "\033[1;38;2;173;216;230m"
#define RESET     "\033[0m"

int main() {
    std::cout << BLUE_BOLD << "--FRAGTRAP CONSTRUCTION TEST--" << RESET << std::endl;
    FragTrap frag("Sütlaç");
    std::cout << std::endl;

    std::cout << BLUE_BOLD << "--FRAGTRAP ATTACK TEST--" << RESET << std::endl;
    frag.attack("Binnur");
    std::cout << std::endl;

    std::cout << BLUE_BOLD << "--FRAGTRAP SPECIAL ABILITY--" << RESET << std::endl;
    frag.highFivesGuys();
    std::cout << std::endl;

    std::cout << BLUE_BOLD << "--ENERGY HIT POINT TEST--" << RESET << std::endl;
    frag.takeDamage(50);
    frag.beRepaired(20);
    std::cout << std::endl;

    std::cout << BLUE_BOLD << "--DESTRUCTOR TEST--" << RESET << std::endl;
    return 0;
}