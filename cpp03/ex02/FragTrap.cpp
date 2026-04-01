#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Default constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) {
    std::cout << "FragTrap Copy constructor called!" << std::endl;
    *this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap Copy assignment operator called!" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->hitPoints == 0) {
        std::cout << "FragTrap " << name << " cannot attack -no Hit points-" << std::endl;
        return;
    }
	if(this->energyPoints == 0){
        std::cout << "FragTrap " << name << " cannot attack -no Energy points-" << std::endl;
        return;
	}
    this->energyPoints -= 1;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << ": Give me a high five!" << std::endl;
}