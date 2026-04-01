#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap Copy constructor called!" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap Copy assignment operator called!" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << name << " cannot attack -no Hit points-" << std::endl;
        return;
    }
	if(this->energyPoints == 0){
        std::cout << "ClapTrap " << name << " cannot attack -no Energy points-" << std::endl;
        return;
	}
    this->energyPoints -= 1;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= amount)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "ClapTrap " << name << " took " << amount << " points of damage! " << hitPoints << " hit points remained" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << name << " cannot repair itself -no Hit points-" << std::endl;
        return;
    }
    if (this->energyPoints == 0) {
        std::cout << "ClapTrap " << name << " cannot repair itself -no Energy points-" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << name << " repaired itself, gaining " << amount << " hit points! Have " << hitPoints << " hit points now."<< std::endl;
}