#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

#define PINK_BOLD "\033[1;38;2;255;182;193m"
#define RESET     "\033[0m"

int main() {
    std::cout << PINK_BOLD << "--CONSTRUCION ORDER TEST--" << RESET << std::endl;
    ScavTrap scav("Sütlaç");
    std::cout << std::endl;

    std::cout << PINK_BOLD << "--ATTACK TEST--" << RESET << std::endl;
    scav.attack("visitor");
    std::cout << std::endl;
    
    std::cout << PINK_BOLD << "--INHERITED FUNCTIONS TEST--" << RESET << std::endl;	
    scav.takeDamage(30);
    scav.beRepaired(20);
    std::cout << std::endl;

    std::cout << PINK_BOLD << "--GUARDGATE TEST--" << RESET << std::endl;
    scav.guardGate();
    std::cout << std::endl;

    std::cout << PINK_BOLD << "--COPY & ASSIGNMENT TEST--" << RESET << std::endl;
    ScavTrap copy_scav(scav);
    ScavTrap assign_scav("Zeytin");
    assign_scav = scav;
    std::cout << std::endl;

    std::cout << PINK_BOLD << "--COMPARISON WITH CLAPTRAP--" << RESET << std::endl;
    ClapTrap clap("Muffin");
    clap.attack("a bird");
    scav.attack("ball");
    std::cout << std::endl;

    std::cout << PINK_BOLD << "--DESTRUCTION ORDER TEST--" << RESET << std::endl;
    return 0;
}