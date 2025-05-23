#include "masking_helpers.h"

int bitboard_to_index(const uint64_t& bitboard)
{
	if (bitboard == 0) throw std::invalid_argument("Invalid bitboard: " + std::to_string(bitboard));
    unsigned long index_long; // index of MSB
    unsigned char is_nonzero = _BitScanReverse64(&index_long, bitboard);
    return static_cast<int>(index_long);
}

std::vector<int> bitboard_to_indices(uint64_t bitboard)
{
	std::vector<int> indices;
    while (bitboard != 0)
    {
        int index = bitboard_to_index(bitboard);
        bitboard &= ~(1ULL << index); // clear the bit at index
        indices.push_back(index);
	}
    return indices;
}

uint64_t square_to_bitboard(const std::string& square)
{
    if (square.length() != 2) throw std::invalid_argument("Invalid square: " + square);
    char file = square[0];
    char rank = square[1];
    if (file < 'a' || file > 'h') throw std::invalid_argument("Invalid file: " + std::string(1, file));
    if (rank < '1' || rank > '8') throw std::invalid_argument("Invalid rank: " + std::string(1, rank));

    int index = (rank - '1') * 8 + (file - 'h') * -1;
    return 1ULL << index;
}

std::string bitboard_to_square(const uint64_t& bitboard)
{
    unsigned long index_long; // index of MSB
    unsigned char is_nonzero = _BitScanReverse64(&index_long, bitboard);
    int index = static_cast<int>(index_long);
    if (index < 0 && index > 63) throw std::invalid_argument("Invalid bitboard: " + std::to_string(bitboard));
    if (fastPowerPos(2, index) != bitboard) throw std::invalid_argument("Invalid bitboard: board contains multiple squares: "
        + std::to_string(fastPowerPos(2, index))
        + " != " + std::to_string(bitboard) + "\n"
        + "Input is base, exp: 2, " + std::to_string(index) + "\n");

    char file = 'h' - (index % 8);
    char rank = '1' + (index / 8);
    return std::string(1, file) + std::string(1, rank);
}