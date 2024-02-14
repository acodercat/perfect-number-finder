#include <gtest/gtest.h>
#include "ThreadManager.h"
#include "PerfectNumber.h"

TEST(ThreadManagerTest, IdentifiesPerfectNumbersCorrectly) {
    std::vector<int> numbers = {6, 28, 496, 8128, 2, 3, 5};
    int numThreads = 4;

    ThreadManager tm(numbers, numThreads);
    tm.startThreads();
    tm.joinThreads();

    int expectedPerfectNumbers = 4;
    ASSERT_EQ(tm.getTotalPerfectNumbers(), expectedPerfectNumbers);
}

TEST(ThreadManagerTest, WorksCorrectlyWithSingleThread) {
    std::vector<int> numbers = {6, 10, 15};
    int numThreads = 1;

    ThreadManager tm(numbers, numThreads);
    tm.startThreads();
    tm.joinThreads();

    int expectedPerfectNumbers = 1;
    ASSERT_EQ(tm.getTotalPerfectNumbers(), expectedPerfectNumbers);
}

TEST(ThreadManagerTest, HandlesZeroPerfectNumbersCorrectly) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int numThreads = 2;

    ThreadManager tm(numbers, numThreads);
    tm.startThreads();
    tm.joinThreads();

    ASSERT_EQ(tm.getTotalPerfectNumbers(), 0);
}

TEST(ThreadManagerTest, HandlesEmptyInputList) {
    std::vector<int> emptyNumbers;
    int numThreads = 2;

    ThreadManager tm(emptyNumbers, numThreads);
    tm.startThreads();
    tm.joinThreads();

    ASSERT_EQ(tm.getTotalPerfectNumbers(), 0);
}

TEST(ThreadManagerTest, ThrowsExceptionWhenZeroOrNegativeThreads) {
    std::vector<int> numbers = {1, 2, 3};

    EXPECT_THROW({
        ThreadManager tm(numbers, 0);
    }, std::invalid_argument);

    EXPECT_THROW({
        ThreadManager tm(numbers, -1);
    }, std::invalid_argument);
}

TEST(ThreadManagerTest, HandlesMoreThreadsThanNumbers) {
    std::vector<int> numbers = {6};
    int numThreads = 4;

    ThreadManager tm(numbers, numThreads);
    tm.startThreads();
    tm.joinThreads();

    ASSERT_EQ(tm.getTotalPerfectNumbers(), 1);
}

