#include "NumberReader.h"

std::vector<int> readNumbers(std::istream& input) {
    std::vector<int> numbers;
    std::string line;
    while (std::getline(input, line)) {
        try {
            int number = std::stoi(line);
            numbers.push_back(number);
        } catch (const std::exception& e) {
            std::cerr << "Error processing number: " << line << " - " << e.what() << std::endl;
        }
    }

    return numbers;
}