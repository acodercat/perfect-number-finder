#include <gtest/gtest.h>
#include <sstream>
#include "NumberReader.h"

TEST(ReadNumbersTest, HandlesValidInput) {
    std::istringstream input("1\n2\n3\n4\n5");
    std::vector<int> expected = {1, 2, 3, 4, 5};
    ASSERT_EQ(readNumbers(input), expected);
}

TEST(ReadNumbersTest, HandlesInvalidInput) {
    std::istringstream input("1\nabc\n3\n4\n");
    std::vector<int> expected = {1, 3, 4};
    ASSERT_EQ(readNumbers(input), expected);
}

TEST(ReadNumbersTest, HandlesNullInput) {
    std::istringstream input("");
    std::vector<int> expected = {};
    ASSERT_EQ(readNumbers(input), expected);
}