#include "conpy.hpp"
#include <regex>

bool isFileConpy(const std::string& fileDir) {
    std::ifstream file(fileDir);

    if (!file) {
        return false;
    }

    std::string firstLine = getLineFromFile(fileDir, 0);
    if (firstLine.find("conpy") != std::string::npos){
        return true;
    }
    return false;
}

std::string getLineFromFile(const std::string& fileDir, std::size_t lineNumber) {
    std::ifstream file(fileDir);

    if (!file) {
        throw std::runtime_error("Unable to open file");
    }

    std::string line;
    std::size_t currentLine = 0;

    while (std::getline(file, line)) {
        if (currentLine == lineNumber) {
            return line;
        }
        ++currentLine;
    }
    throw std::out_of_range("Line number out of range");
}

std::size_t getLineCountFromFile(const std::string& fileDir) {
    std::ifstream file(fileDir);

    if (!file) {
        throw std::runtime_error("Unable to open file");
    }

    std::size_t lineCount = 0;
    std::string line;

    // Read through each line and count them
    while (std::getline(file, line)) {
        ++lineCount;
    }

    // Handle the case for empty files or files with only newline characters
    if (file.eof() && lineCount == 0 && file.peek() == std::ifstream::traits_type::eof()) {
        return 0;
    }

    return lineCount;
}

lineTypes getLineTypeFromFile(const std::string& fileDir, std::size_t lineNumber) {
    std::string line = getLineFromFile(fileDir, lineNumber);
    if (line.rfind("#", 0) == 0) {
        return lineTypes::COMMENT;
    }else if(line.rfind("import", 0) == 0 || line.rfind("importf", 0) == 0){
        return lineTypes::IMPORT;
    }else if(line.find("(") != std::string::npos && line.find(")") != std::string::npos){
        return lineTypes::FUNCTION;
    }else if(line.rfind("class", 0) == 0){
        std::cout << "classes are not supported" << std::endl;
        return lineTypes::CLASS;
    }else if(line.rfind("def", 0) == 0){
        return lineTypes::DECLAREFUNC;
    }
    return lineTypes::OTHER;
}

std::string lineTypeToString(lineTypes type) {
    switch (type) {
        case lineTypes::FUNCTION:
            return "FUNCTION";
        case lineTypes::VARIABLE:
            return "VARIABLE";
        case lineTypes::CLASS:
            return "CLASS";
        case lineTypes::DECLAREFUNC:
            return "DECLAREFUNC";
        case lineTypes::IMPORT:
            return "IMPORT";
        case lineTypes::COMMENT:
            return "COMMENT";
        case lineTypes::OTHER:
            return "OTHER";
        default:
            return "UNKNOWN";
    }
}

std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = str.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }

    tokens.push_back(str.substr(start)); // Add the last token

    return tokens;
}