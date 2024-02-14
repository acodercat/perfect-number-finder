#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <string>
#include <atomic>
#include "PerfectNumber.h"


std::atomic<int> totalPerfectNumbers(0);

void isPerfectThread(const std::vector<int>& numbers, int threadId, int numThreads) {
    for (size_t i = threadId; i < numbers.size(); i += numThreads) {
        std::cout << "Thread " << threadId + 1 << " processing number: " << numbers[i] << std::endl;
        if (isPerfect(numbers[i])) {
            std::cout << "Thread " << threadId << " found perfect number: " << numbers[i] << std::endl;
            totalPerfectNumbers++;
        }
    }
}

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
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }


    std::string line;
    std::vector<int> numbers;
    while (std::getline(file, line)) {
        try {
            int number = std::stoi(line);
            numbers.push_back(number);            
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid number found: " << line << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Number out of range: " << line << std::endl;
        }
    }

    file.close();

    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(isPerfectThread, std::ref(numbers), i, numThreads);
    }


    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Total perfect numbers: " << totalPerfectNumbers << std::endl;
    return 0;
}


