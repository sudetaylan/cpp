#include "Sed.hpp"
#include <fstream>

int main(int argc, char **argv)
{
	if(argc != 4){
		std::cout << "Usage: ./sed <filename> <string_old> <string_new>\n";
		return 1;
	}
	std::string s1 = argv[2];
    if (s1.empty()) {
        std::cerr << "Error: The string to find <string_old> cannot be empty!" << std::endl;
        return 1;
    }
	Sed mySed(argv[1], argv[2], argv[3]);
	mySed.processLines();

}