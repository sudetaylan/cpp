#include "Fixed.hpp"

const int Fixed::bits;

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

Fixed::~Fixed() {}


int Fixed::getRawBits(void) const {
    return this->value; 
}
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}
float Fixed::toFloat(void) const {
    return (float)this->value / (1 << bits);
}
int Fixed::toInt(void) const {
    return this->value >> bits;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}

bool Fixed::operator<(Fixed const& obj) const{
	return (value < obj.value);
}

bool Fixed::operator>(Fixed const& obj) const{
	return (value > obj.value);
}
bool Fixed::operator<=(Fixed const& obj) const{
	return (value <= obj.value);
}

bool Fixed::operator>=(Fixed const& obj) const{
	return (value >= obj.value);
}
bool Fixed::operator==(Fixed const& obj) const{
	return (value == obj.value);
}

bool Fixed::operator!=(Fixed const& obj) const{
	return (value != obj.value);
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed res;
    res.setRawBits(this->value + other.value);
    return res;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed res;
    res.setRawBits(this->value - other.value);
    return res;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed res;
    long tmp = (long)this->value * (long)other.value;
    res.setRawBits((int)(tmp >> bits));
    return res;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed res;
    if (other.value != 0)
        res.setRawBits((int)(((long)this->value << bits) / other.value));
    return res;
}

Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->value++;
    return tmp;
}
Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->value--;
    return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream &o, const Fixed &other) {
    o << other.toFloat();
    return o;
}