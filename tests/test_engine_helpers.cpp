#include <gtest/gtest.h>
#include "engine_helpers.h"

//fastPower only handles integers and non-negative exponents
TEST(FastPowerTest, HandlesZero)
{
    EXPECT_EQ(fastPower(0, 0), 1);
    EXPECT_EQ(fastPower(10, 0), 1);
    EXPECT_EQ(fastPower(-1000, 0), 1);
}

TEST(FastPowerTest, HandlesNormal)
{
    EXPECT_EQ(fastPower(2, 2), 4);
    EXPECT_EQ(fastPower(2, 5), 32);
    EXPECT_EQ(fastPower(10, 5), 100000);
    EXPECT_EQ(fastPower(-5, 3), -125);
    EXPECT_EQ(fastPower(-1, 11111111110), 1);
    EXPECT_EQ(fastPower(-1, 11111111111), -1);
}