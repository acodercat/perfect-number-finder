#include "ThreadManager.h"
#include "PerfectNumber.h"

// Initializes the ThreadManager with a list of numbers and the number of threads 
ThreadManager::ThreadManager(const std::vector<int>& numbers, int numThreads)
    : numbers(numbers), numThreads(numThreads), totalPerfectNumbers(0) {
    if (numThreads <= 0) {
        throw std::invalid_argument("Number of threads must be greater than 0.");
    }
}

// Function to start the worker threads
void ThreadManager::startThreads() {
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(&ThreadManager::checkPerfectNumbersInRange, this, i);
    }
}

// Function to join all worker threads, ensuring they have completed their execution
void ThreadManager::joinThreads() {
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

// Function to return the total number of perfect numbers found by all threads
int ThreadManager::getTotalPerfectNumbers() const {
    return totalPerfectNumbers.load();
}

// Worker function for each thread to check a subrange of numbers for perfection
void ThreadManager::checkPerfectNumbersInRange(int threadId) {
    for (size_t i = threadId; i < numbers.size(); i += numThreads) {
        // Check if the current number is perfect
        if (isPerfect(numbers[i])) {
            std::cout << "Thread " << threadId << " found perfect number: " << numbers[i] << std::endl;
            // Safely increment the count of total perfect numbers
            totalPerfectNumbers++;
        }
    }
}
