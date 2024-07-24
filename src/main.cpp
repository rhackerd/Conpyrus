#include <iostream> // C++ standard I/O library
#include "conpy.hpp" // Include header for functions and enums

// Main function
int main() {
    std::string test = "file.conpy"; // Test file path
    std::size_t fileSize = getLineCountFromFile(test); // Get line count from file
    lineTypes type = getLineTypeFromFile(test, 2); // Get line type from file

    // Print the file size in lines
    std::cout << "File size in lines: " << fileSize << std::endl;

    // Print the line type
    std::cout << "Line type: " << lineTypeToString(type) << std::endl;

    // Check if the file is a Conpy file
    bool result = isFileConpy(test);
    if (result) {
        std::cout << "Yes, it is a Conpy file." << std::endl;
    } else {
        std::cout << "No, it is not a Conpy file." << std::endl;
    }

    return 0;
}
