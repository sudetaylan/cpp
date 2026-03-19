#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP

#include <string>
#include <iostream>

class HarlFilter{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	
	public:
		void complain(std::string level);
};

#endif