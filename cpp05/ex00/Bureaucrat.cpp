#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("Anyone"), grade(150){
    std::cout << name << "bureaucrat default constructor called! " << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat& other) : name(other.name){
    std::cout << name << "bureaucrat copy constructor called! " << std::endl;
    *this = other;
}
Bureaucrat& Bureaucrat::operator=(Bureaucrat& other){
    std::cout << name << "bureaucrat copy assignment called! " << std::endl;
    if(this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat(){
    std::cout << name << " bureaucrat destructor called! " << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const long long grade) : name(name){
    std::cout << name << " bureaucrat constructor called! " << std::endl;
    if(grade > MIN)
        throw GradeTooHighException();
    else if(grade < MAX)
        throw GradeTooLowException();
    this->grade = grade; 
}

std::string Bureaucrat::getName() const{
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

int Bureaucrat::incrementGrade(){
    if(grade <= MAX)
        throw GradeTooHighException();
    grade--;
    return grade;
}

int Bureaucrat::decrementGrade(){
    if(grade >= MIN)
        throw GradeTooLowException();
    grade++;
    return grade;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& br)
{
    o << br.getName() << ", bureaucrat grade " << br.getGrade();
    return o;
}