#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()){
    this->type = "Cat"; 
    std::cout << "Cat default constructor called!" << std::endl;
}

Cat::~Cat(){
    delete this->brain;
    std::cout << "Cat destructor called!" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj), brain(NULL) {
    std::cout << "Cat copy constructor called!" << std::endl;
    *this = obj;
}

Cat& Cat::operator=(const Cat &obj) {
    std::cout << "Cat copy assignment called!" << std::endl;
    if (this != &obj) {
        this->type = obj.type;

        delete this->brain;

        this->brain = new Brain(*obj.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat: meowww 🐈‍⬛" << std::endl;
}
