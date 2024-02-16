#include "NumberReader.h"

// Function to read numbers from a given input stream and store them in a vector
std::vector<int> readNumbers(std::istream& input) {
    std::vector<int> numbers;
    std::string line;
    // Read the input line by line until the end of the stream is reached
    while (std::getline(input, line)) {
        try {
            // Attempt to convert the current line to an integer
            int number = std::stoi(line);
            // If successful, add the integer to the vector of numbers
            numbers.push_back(number);
        } catch (const std::exception& e) {
            std::cerr << "Error processing number: " << line << " - " << e.what() << std::endl;
        }
    }

    return numbers;
}