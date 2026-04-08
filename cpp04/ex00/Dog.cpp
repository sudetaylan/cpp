#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    this->type = "Dog"; 
    std::cout << "Dog default constructor called!" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj) {
    std::cout << "Cat copy constructor called!" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(const Dog &obj) {
    std::cout << "Cat copy assignment called!" << std::endl;
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog: hav havv 🦮" << std::endl;
}
