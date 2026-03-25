#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val){
    std::cout << "Int constructor called" << std::endl;
    this->value = val << bits;
}

Fixed::Fixed(const float val){
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(val * (1 << bits));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return((float)this->value / (float)(1 << bits));
}

int Fixed::toInt(void) const
{
    return(this->value >> bits);
}

bool Fixed::operator<(Fixed const& obj){
	return (value < obj.value);
}

bool Fixed::operator>(Fixed const& obj){
	return (value > obj.value);
}
bool Fixed::operator<=(Fixed const& obj){
	return (value <= obj.value);
}

bool Fixed::operator>=(Fixed const& obj){
	return (value >= obj.value);
}
bool Fixed::operator==(Fixed const& obj){
	return (value == obj.value);
}

bool Fixed::operator!=(Fixed const& obj){
	return (value != obj.value);
}

Fixed Fixed::operator+(Fixed const& obj){
	return(value + obj.value);
}

Fixed Fixed::operator-(Fixed const& obj){
	return(value - obj.value);
}

Fixed Fixed::operator*(Fixed const& obj){
	return(value * obj.value);
}

Fixed Fixed::operator/(Fixed const& obj){
	return(value / obj.value);
}

std::ostream& operator<<(std::ostream& o, Fixed const& obj) {
    o << obj.toFloat();
    return o;
}