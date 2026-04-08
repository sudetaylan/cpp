#ifndef BRAIN_HPP
#define BRAIN_HPP

#define N 100
#include "Animal.hpp"

class Brain{
	private:
		std::string ideas[N];
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
};

#endif