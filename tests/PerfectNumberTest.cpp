#include <gtest/gtest.h>
#include "PerfectNumber.h"


TEST(PerfectNumberTest, IsPerfect_PositiveCases) {
    ASSERT_TRUE(isPerfect(6));
    ASSERT_TRUE(isPerfect(28));
    ASSERT_TRUE(isPerfect(496));
}


TEST(PerfectNumberTest, IsPerfect_NegativeCases) {
    ASSERT_FALSE(isPerfect(1));
    ASSERT_FALSE(isPerfect(2));
    ASSERT_FALSE(isPerfect(281));
}

TEST(PerfectNumberTest, HandlesLargeNumber) {
    ASSERT_FALSE(isPerfect(99999999));
}
