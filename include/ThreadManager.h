#pragma once

#include <vector>
#include <thread>
#include <atomic>
#include <iostream>

class ThreadManager {
public:
    // Constructor: Initializes a ThreadManager with a list of numbers and a specified number of threads
    ThreadManager(const std::vector<int>& numbers, int numThreads);

    // Function to start all threads, each will execute checkPerfectNumbersInRange
    void startThreads();

    // Function to join all threads, ensuring they complete their execution before proceeding
    void joinThreads();

    // Function to return the total number of perfect numbers found by all threads
    int getTotalPerfectNumbers() const;

private:
    std::vector<std::thread> threads; // Vector to store all the worker threads
    std::atomic<int> totalPerfectNumbers; // Atomic integer to store the total count of perfect numbers found
    std::vector<int> numbers; // Vector to store the list of numbers to be checked
    int numThreads; // Integer to store the number of threads to be used

    // Private member function for threads to execute, checks for perfect numbers in a range of the list
    void checkPerfectNumbersInRange(int threadId);
};
