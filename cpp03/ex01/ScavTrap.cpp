#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) {
    std::cout << "ScavTrap Copy constructor called!" << std::endl;
    *this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap Copy assignment operator called!" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << name << " cannot attack -no Hit points-" << std::endl;
        return;
    }
	if(this->energyPoints == 0){
        std::cout << "ScavTrap " << name << " cannot attack -no Energy points-" << std::endl;
        return;
	}
    this->energyPoints -= 1;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}