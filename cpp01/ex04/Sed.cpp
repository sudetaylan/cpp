#include "Sed.hpp"
#include <string>

Sed::Sed(std::string filename, std::string s1, std::string s2) 
    : filename(filename), s1(s1), s2(s2) {}

std::string Sed::replaceString(std::string line)
{
    std::string newLine = "";
    size_t pos = 0;
    size_t foundPos;

    if (line.empty()) return line;
    while ((foundPos = line.find(s1, pos)) != std::string::npos) {
        newLine.append(line, pos, foundPos - pos);
        newLine.append(s2);
        pos = foundPos + s1.length();
    }
    newLine.append(line, pos, std::string::npos);
    return newLine;
}

int Sed::processLines() 
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file!" << std::endl;
        return 1;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file!" << std::endl;
        inputFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceString(line);

        if (!inputFile.eof()) {
            outputFile << "\n";
        }
    }
    inputFile.close();
    outputFile.close();
    return 0;
}