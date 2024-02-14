#pragma once

#include <vector>
#include <thread>
#include <atomic>
#include <iostream>

class ThreadManager {
public:
    ThreadManager(const std::vector<int>& numbers, int numThreads);

    void startThreads();
    void joinThreads();
    int getTotalPerfectNumbers() const;

private:
    std::vector<std::thread> threads;
    std::atomic<int> totalPerfectNumbers;
    std::vector<int> numbers;
    int numThreads;

    void checkPerfectNumbersInRange(int threadId);
};
