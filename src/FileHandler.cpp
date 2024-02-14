#include "FileHandler.h"

std::vector<int> readFileNumbers(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file" << std::endl;
        return std::vector<int>();
    }

    std::vector<int> numbers;
    std::string line;
    while (std::getline(file, line)) {
        try {
            int number = std::stoi(line);
            numbers.push_back(number);
        } catch (const std::exception& e) {
            std::cerr << "Error processing number: " << line << " - " << e.what() << std::endl;
        }
    }

    return numbers;
}