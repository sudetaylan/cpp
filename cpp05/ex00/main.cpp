#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat b("A", 40);
    try{
        b.decrementGrade();
    }
    catch(std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    Bureaucrat c("B", 150);
    try{
        c.decrementGrade();
    }
    catch(std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    Bureaucrat d("C", 1);
    try{
        d.incrementGrade();
    }
    catch(std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}