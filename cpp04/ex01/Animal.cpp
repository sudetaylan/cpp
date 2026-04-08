#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal default constructor called!" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called!" << std::endl;
}

Animal::Animal(const Animal &obj) {
    std::cout << "Animal copy constructor called!" << std::endl;
    *this = obj;
}

Animal& Animal::operator=(const Animal &obj) {
    std::cout << "Animal copy assignment called!" << std::endl;
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal: animal sounds" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}