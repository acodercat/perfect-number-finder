#include "ThreadManager.h"
#include "PerfectNumber.h"

ThreadManager::ThreadManager(const std::vector<int>& numbers, int numThreads)
    : numbers(numbers), numThreads(numThreads), totalPerfectNumbers(0) {
    if (numThreads <= 0) {
        throw std::invalid_argument("Number of threads must be greater than 0.");
    }
}

void ThreadManager::startThreads() {
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(&ThreadManager::checkPerfectNumbersInRange, this, i);
    }
}

void ThreadManager::joinThreads() {
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}


int ThreadManager::getTotalPerfectNumbers() const {
    return totalPerfectNumbers.load();
}

void ThreadManager::checkPerfectNumbersInRange(int threadId) {
    for (size_t i = threadId; i < numbers.size(); i += numThreads) {
        if (isPerfect(numbers[i])) {
            std::cout << "Thread " << threadId << " found perfect number: " << numbers[i] << std::endl;
            totalPerfectNumbers++;
        }
    }
}
