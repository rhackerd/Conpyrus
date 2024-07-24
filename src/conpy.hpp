#ifndef CONPY_H
#define CONPY_H

#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>

enum class lineTypes {
    FUNCTION, 
    VARIABLE,
    CLASS,
    DECLAREFUNC,
    IMPORT,
    COMMENT,
    OTHER
};

bool isFileConpy(const std::string& fileDir);
std::string getLineFromFile(const std::string& fileDir, std::size_t lineNumber);
lineTypes getLineTypeFromFile(const std::string& fileDir, std::size_t lineNumber);
std::size_t getLineCountFromFile(const std::string& fileDir);
std::string lineTypeToString(lineTypes);
std::vector<std::string> split(const std::string& str, const std::string& delimiter);


#endif