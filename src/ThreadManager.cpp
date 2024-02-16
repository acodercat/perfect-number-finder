#include "ThreadManager.h"
#include "PerfectNumber.h"

// Initializes the ThreadManager with a list of numbers and the number of threads 
ThreadManager::ThreadManager(const std::vector<int>& numbers, int numThreads) {
    if (numThreads <= 0) {
        throw std::invalid_argument("Number of threads must be greater than 0.");
    }
    if (numbers.empty()) {
        throw std::invalid_argument("Input number list cannot be empty.");
    }

    this->numbers = numbers;
    this->numThreads = numThreads;
    this->totalPerfectNumbers = 0;
}

// Function to start the worker threads
void ThreadManager::startThreads() {
    for (int i = 0; i < numThreads; ++i) {
        auto future = std::async(std::launch::async, &ThreadManager::checkPerfectNumbersInRange, this, i);
        futures.push_back(std::move(future));
    }
}

// Function to join all worker threads, ensuring they have completed their execution
void ThreadManager::joinThreads() {
    for (auto& future : futures) {
        totalPerfectNumbers += future.get();
    }
}

// Function to return the total number of perfect numbers found by all threads
int ThreadManager::getTotalPerfectNumbers() const {
    return totalPerfectNumbers;
}

// Worker function for each thread to check a subrange of numbers for perfection
int ThreadManager::checkPerfectNumbersInRange(int threadId) {
    int count = 0;
    for (size_t i = threadId; i < numbers.size(); i += numThreads) {
        // Check if the current number is perfect
        if (isPerfect(numbers[i])) {
            std::cout << "Thread " << threadId << " found perfect number: " << numbers[i] << std::endl;
            count++;
        }
    }
    return count;
}
