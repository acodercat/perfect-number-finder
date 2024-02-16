#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include "NumberReader.h"
#include "ThreadManager.h"

int main(int argc, char* argv[]) {


    // Check command line arguments for correct usage
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

    // Attempt to open the file
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    // Read numbers from the file into a vector
    std::vector<int> numbers = readNumbers(file);

    if (numbers.empty()) {
        std::cerr << "No numbers to process." << std::endl;
        return 1;
    }
    // Initialize the ThreadManager
    ThreadManager threadManager(numbers, numThreads);
    threadManager.launchTasks();
    int totalPerfectNumbers = threadManager.collectResults();

    std::cout << "Total perfect numbers: " << totalPerfectNumbers << std::endl;
    return 0;
}