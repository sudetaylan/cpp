#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    this->type = "Cat"; 
    std::cout << "Cat default constructor called!" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called!" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj) {
    std::cout << "Cat copy constructor called!" << std::endl;
    *this = obj;
}

Cat& Cat::operator=(const Cat &obj) {
    std::cout << "Cat copy assignment called!" << std::endl;
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat: meowww 🐈‍⬛" << std::endl;
}
