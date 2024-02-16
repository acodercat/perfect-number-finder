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
}

/**
 * Launches a series of asynchronous tasks to check for perfect numbers within the provided list.
 * Each task is responsible for a subset of the list, determined by the thread ID.
 */
void ThreadManager::launchTasks() {
    for (int i = 0; i < numThreads; ++i) {
        auto future = std::async(std::launch::async, &ThreadManager::checkPerfectNumbersInRange, this, i);
        futures.push_back(std::move(future));
    }
}

/**
 * Collects the results from all launched asynchronous tasks.
 * Each future holds the result from one task, and this function aggregates those results.
 * 
 * @return The total number of perfect numbers found by all tasks.
 */
int ThreadManager::collectResults() {
    int totalPerfectNumbers = 0;
    for (auto& future : futures) {
        totalPerfectNumbers += future.get();
    }
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
