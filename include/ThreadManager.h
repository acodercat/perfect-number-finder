#pragma once

#include <vector>
#include <thread>
#include <iostream>
#include <future>


class ThreadManager {
public:
    // Constructor: Initializes a ThreadManager with a list of numbers and a specified number of threads
    ThreadManager(const std::vector<int>& numbers, int numThreads);

    /**
     * Launches a series of asynchronous tasks to check for perfect numbers within the provided list.
     * Each task is responsible for a subset of the list, determined by the thread ID.
     */
    void launchTasks();

    /**
     * Collects the results from all launched asynchronous tasks and calculates the total number
     * of perfect numbers found. Each future holds the result from one task, and this function
     * aggregates those results.
     * 
     * @return The total number of perfect numbers found by all tasks.
     */
    int collectResults();

private:
    std::vector<std::future<int>> futures; // Futures to hold the return values from threads
    std::vector<int> numbers; // Vector to store the list of numbers to be checked
    int numThreads; // Integer to store the number of threads to be used

    // Private member function for threads to execute, checks for perfect numbers in a range of the list
    int checkPerfectNumbersInRange(int threadId);
};
