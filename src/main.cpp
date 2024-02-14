#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include "PerfectNumber.h"
#include "FileHandler.h"
#include "ThreadManager.h"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <filename>" <<" <number of threads>" << std::endl;
        std::cerr << "<filename>: Path to the file containing numbers, one per line." << std::endl;
        std::cerr << "<number of threads>: The number of threads to use for processing." << std::endl;
        return 1;
    }

    // Extract the number of threads from the command line arguments
    int numThreads = std::atoi(argv[2]);

    // Check if the number of threads is valid
    if (numThreads <= 0) {
        std::cerr << "Invalid number of threads. Please specify a positive integer.\n";
        return 1;
    }

    std::string filename = argv[1];

    std::vector<int> numbers = readFileNumbers(filename);

    if (numbers.empty()) {
        std::cerr << "No numbers to process." << std::endl;
        return 1;
    }
    
    ThreadManager threadManager(numbers, numThreads);
    threadManager.startThreads();
    threadManager.joinThreads();

    std::cout << "Total perfect numbers: " << threadManager.getTotalPerfectNumbers() << std::endl;
    return 0;
}


