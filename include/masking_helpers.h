#ifndef MASKING_HELPERS_H
#define MASKING_HELPERS_H

#include <intrin.h> // For _BitScanReverse64
#include <iostream>
#include <string>
#include <vector>


#include "math_utils.h"

// returns the index of the MSB set in a bitboard
int bitboard_to_index(const uint64_t& bitboard);
// returns all indices set in a bitboard
std::vector<int> bitboard_to_indices(const uint64_t& bitboard);

// handles a1 -> a8, through h1 -> h8 (only lowercase)
// a1 -> 0x80/128, b2 -> 0x4000/16384
uint64_t square_to_bitboard(const std::string& square);
// for one square only
std::string bitboard_to_square(const uint64_t& bitboard);


#endif