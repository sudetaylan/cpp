#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) {
    this->type = "Dog";
    std::cout << "Dog default constructor called!" << std::endl;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj), brain(NULL) {
    std::cout << "Dog copy constructor called!" << std::endl;
    *this = obj;
}

Dog &Dog::operator=(const Dog &obj) {
    std::cout << "Dog assignment operator called!" << std::endl;
    if (this != &obj) {
        this->type = obj.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*obj.brain); 
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog: hav havv 🦮" << std::endl;
}
