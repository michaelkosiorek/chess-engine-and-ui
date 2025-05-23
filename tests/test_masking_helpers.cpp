#include <gtest/gtest.h>
#include "masking_helpers.h"

// ordered like this because h1 = 1, g1 = 2, f1= 4, etc.
std::vector<std::string> all_squares = { "h1", "g1", "f1", "e1", "d1", "c1", "b1", "a1",
                                            "h2", "g2", "f2", "e2", "d2", "c2", "b2", "a2",
                                            "h3", "g3", "f3", "e3", "d3", "c3", "b3", "a3",
                                            "h4", "g4", "f4", "e4", "d4", "c4", "b4", "a4",
                                            "h5", "g5", "f5", "e5", "d5", "c5", "b5", "a5",
                                            "h6", "g6", "f6", "e6", "d6", "c6", "b6", "a6",
                                            "h7", "g7", "f7", "e7", "d7", "c7", "b7", "a7",
                                            "h8", "g8", "f8", "e8", "d8", "c8", "b8", "a8" };

//tests all valid chess squares
TEST(SquareToBitboardTest, TestAll64SquaresSTB)
{
    uint64_t expected_bitboard = 1;
    for (int i = 0; i < 64; i++)
    {
        std::cout << "Result: " << square_to_bitboard(all_squares[i]) << "\n expected: " << expected_bitboard << std::endl;
        EXPECT_EQ(square_to_bitboard(all_squares[i]), expected_bitboard);

        expected_bitboard <<= 1;
    }
}

TEST(SquareToBitboardTest, TestAssertsSTB)
{
    EXPECT_THROW(square_to_bitboard("a"), std::invalid_argument);
    EXPECT_THROW(square_to_bitboard("aaa"), std::invalid_argument);
    EXPECT_THROW(square_to_bitboard("h9"), std::invalid_argument);
    EXPECT_THROW(square_to_bitboard("h0"), std::invalid_argument);
    EXPECT_THROW(square_to_bitboard("A1"), std::invalid_argument);
    EXPECT_THROW(square_to_bitboard("i1"), std::invalid_argument);
}

TEST(BitboardToSquareTest, TestAll64SquaresBTS)
{
    uint64_t expected_bitboard = 1;
    for (int i = 0; i < 64; i++)
    {
        std::cout << bitboard_to_square(expected_bitboard) << "\n expected: "<< all_squares[i] << std::endl;
        EXPECT_EQ(bitboard_to_square(expected_bitboard), all_squares[i]);
        expected_bitboard <<= 1;
    }
}

TEST(BitboardToSquareTest, TestAssertsBTS)
{
    // too small
    EXPECT_THROW(bitboard_to_square(0), std::invalid_argument);
    EXPECT_THROW(bitboard_to_square(-1), std::invalid_argument);
    EXPECT_THROW(bitboard_to_square(-2), std::invalid_argument);
    EXPECT_THROW(bitboard_to_square(-3), std::invalid_argument);

    // multiple squares on board
    EXPECT_THROW(bitboard_to_square((1ULL << 63) + 1), std::invalid_argument);
    EXPECT_THROW(bitboard_to_square(0x81), std::invalid_argument);
    EXPECT_THROW(bitboard_to_square(0xF), std::invalid_argument);
}
