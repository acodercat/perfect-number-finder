#pragma once

#include <vector>
#include <thread>
#include <iostream>
#include <future>


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
    std::vector<std::future<int>> futures; // Futures to hold the return values from threads
    int totalPerfectNumbers = 0; // The total count of perfect numbers found
    std::vector<int> numbers; // Vector to store the list of numbers to be checked
    int numThreads; // Integer to store the number of threads to be used

    // Private member function for threads to execute, checks for perfect numbers in a range of the list
    int checkPerfectNumbersInRange(int threadId);
};
