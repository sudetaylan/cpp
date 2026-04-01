#include "ClapTrap.hpp"
#include <iostream>

#define LILA_BOLD "\033[1;38;2;200;162;200m"
#define RESET     "\033[0m"

int main() {
    std::cout << LILA_BOLD << "--CONSTRUCTOR TEST--" << RESET << std::endl;
    ClapTrap s1("Yolo");
    ClapTrap s2("Lizzard");

    std::cout << LILA_BOLD << "\n--ACTION TEST--" << RESET << std::endl;
    s1.attack("Yolo");
    s2.takeDamage(5);
    s2.beRepaired(3);

    std::cout << LILA_BOLD << "\n--ENERGY TEST--" << RESET << std::endl;
    for (int i = 0; i < 10; i++) {
        s1.attack("tuxedo");
    }
    s1.beRepaired(5);

    std::cout << LILA_BOLD << "\n--DEATH TEST--" << RESET << std::endl;
    s2.takeDamage(20);
    s2.attack("Yolo");

    std::cout << LILA_BOLD << "\n--OCF TEST--" << RESET << std::endl;
    ClapTrap s3(s1);
    ClapTrap s4;
    s4 = s2;

    std::cout << LILA_BOLD << "\n--DESTRUCTOR TEST--" << RESET << std::endl;
    return 0;
}