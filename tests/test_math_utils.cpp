#include <gtest/gtest.h>
#include "math_utils.h"


//fastPowerPos only handles non-negative integer bases and exponents
TEST(FastPowerPosTest, HandlesZero)
{
    EXPECT_EQ(fastPowerPos(0, 0), 1);
    EXPECT_EQ(fastPowerPos(10, 0), 1);
    EXPECT_EQ(fastPowerPos(1000, 0), 1);
}

TEST(FastPowerPosTest, HandlesNormal)
{
    EXPECT_EQ(fastPowerPos(2, 2), 4) << "test 1 failed";
    EXPECT_EQ(fastPowerPos(2, 5), 32) << "test 2 failed";
    EXPECT_EQ(fastPowerPos(10, 5), 100000) << "test 3 failed";
    EXPECT_EQ(fastPowerPos(5, 3), 125) << "test 4 failed";
    EXPECT_EQ(fastPowerPos(1, 11111110), 1) << "test 5 failed";
    EXPECT_EQ(fastPowerPos(1, 11111111), 1) << "test 6 failed";
}
