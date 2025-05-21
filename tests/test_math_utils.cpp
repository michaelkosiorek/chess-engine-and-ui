#include <gtest/gtest.h>
#include "math_utils.h"


//fastPower only handles integers and non-negative exponents
TEST(FastPowerTest, HandlesZero)
{
    EXPECT_EQ(fastPower(0, 0), 1);
    EXPECT_EQ(fastPower(10, 0), 1);
    EXPECT_EQ(fastPower(-1000, 0), 1);
}

TEST(FastPowerTest, HandlesNormal)
{
    EXPECT_EQ(fastPower(2, 2), 4) << "test 1 failed";
    EXPECT_EQ(fastPower(2, 5), 32) << "test 2 failed";
    EXPECT_EQ(fastPower(10, 5), 100000) << "test 3 failed";
    EXPECT_EQ(fastPower(-5, 3), -125) << "test 4 failed";
    EXPECT_EQ(fastPower(-1, 11111110), 1) << "test 5 failed";
    EXPECT_EQ(fastPower(-1, 11111111), -1) << "test 6 failed";
}
